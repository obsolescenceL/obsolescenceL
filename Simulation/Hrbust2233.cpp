/*************************************************************************
     File Name: Hrbust2233.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月28日 星期六 22时06分45秒
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
string s;
char ch[4][4];
int k;

void print_ch(){
  int i,j;
  if(k==1){
    for(j=0;j<4;++j)
      for(i=3;i>=0;--i)
        cout<<ch[i][j];
  }else if(k==2){
    for(i=3;i>=0;--i)
      for(j=3;j>=0;--j)
        cout<<ch[i][j];
  }else{
    for(j=3;j>=0;--j)
      for(i=0;i<4;++i)
        cout<<ch[i][j];
  }
}

int main(){
  while(cin>>k){
    getchar();
    s.clear();
    getline(cin,s);
    int i=0,j,l;
    while(i<s.size()){
      memset(ch,0,sizeof ch);
      for(j=0;j<4&&s[i];++j)
        for(l=0;l<4&&s[i];++l)
          ch[j][l]=s[i++];
      if(j==4&&l==4) print_ch();
      else{
        for(;l<4;++l)
          ch[j-1][l]='-';
        for(;j<4;++j)
          for(l=0;l<4;++l)
            ch[j][l]='-';
        print_ch();
      }
    }
    cout<<'\n';
  }
}
