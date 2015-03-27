/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月27日 星期五 00时35分59秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;
char s[200002],t;
int a[100001];

int main(){
  ios::sync_with_stdio(0);
  int m,i,x;
  while(cin>>s+1){
    int len=strlen(s+1);
    //cout<<"len="<<len<<endl;
    memset(a,0,sizeof a);
    cin>>m;
    for(i=0;i<m;++i){
      cin>>x;
      a[x]++;
    }
    for(i=1;i<=(len+1)/2;++i){
      a[i]+=a[i-1];
      //cout<<"a["<<i<<"]="<<a[i]<<endl;
      if(a[i]%2)
        t=s[i],s[i]=s[len-i+1],s[len-i+1]=t;
    }
    cout<<s+1<<'\n';
  }
}
