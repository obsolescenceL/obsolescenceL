/*************************************************************************
     File Name: cf1.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月28日 星期六 21时42分55秒
 ************************************************************************/
#include<cstdio>
#include<map>
#include<iostream>
using namespace std;
char mp[10];
map<char,int> m;

int main(){
  m['q']=m['Q']=9;
  m['r']=m['R']=5;
  m['b']=m['B']=3;
  m['n']=m['N']=3;
  m['p']=m['P']=1;
  int i,j,w=0,b=0;
  for(i=0;i<8;++i){
    scanf("%s",mp);
    for(j=0;j<8;++j){
      if(mp[j]=='.')continue;
      if(mp[j]>='A'&&mp[j]<='Z')w+=m[mp[j]];
      else if(mp[j]>='a'&&mp[j]<='z')b+=m[mp[j]];
    }
  //cout<<w<<' '<<b<<endl;
  }
  if(b==w)puts("Draw");
  else if(b>w)puts("Black");
  else puts("White");
}
