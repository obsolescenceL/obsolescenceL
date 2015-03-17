/*************************************************************************
     File Name: bc1.cpp
     ID: obsolesence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月14日 星期六 19时04分54秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
string a[110];

int main(){
  ios::sync_with_stdio(false);
  int n,b,i,j,num1,num2;
  while(cin>>n>>b){
    //cout<<"gege"<<endl;
    cin>>a[0];
    for(i=1;i<n;++i){
      cin>>a[i];
      int len1=a[0].size(),len2=a[i].size();
      int len=min(len1,len2);
      for(j=1;j<=len;++j){
        if(isdigit(a[0][len1-j])) num1=a[0][len1-j]-'0';
        else num1=a[0][len1-j]-'a'+10;
        if(isdigit(a[i][len2-j])) num2=a[i][len2-j]-'0';
        else num2=a[i][len2-j]-'a'+10;
        num1+=num2;num1%=b;
        if(len1>=len2){
          if(num1<10) a[0][len1-j]=num1+'0';
          else a[0][len1-j]=num1-10+'a';
        }else{
          if(num1<10) a[i][len2-j]=num1+'0';
          else a[i][len2-j]=num1-10+'a';
        }
      }
      if(len1<len2) a[0]=a[i];
    }
    bool flag=1;
    for(i=0;a[0][i];++i)
      if(a[0][i]!='0') {flag=0;break;}
    for(;a[0][i];++i)cout<<a[0][i];
    if(flag)cout<<'0';
    cout<<'\n';
  }
}

