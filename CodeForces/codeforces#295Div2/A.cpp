/*************************************************************************
     File Name: codef1.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月02日 星期一 14时59分01秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
char s[110];
bool vis[30];

int main(){
  int n;
  while(~scanf("%d",&n)){
    memset(vis,0,sizeof vis);
    scanf("%s",s);
    //cout<<s<<endl;
    bool flag=1;
    for(int i=0;i<n;++i){
      if(s[i]>='a')s[i]-=32;
      vis[s[i]-'A']=1;
    }
    for(int i=0;i<26;++i)
      if(!vis[i])flag=0;
    if(flag)puts("YES");
    else puts("NO");
  }
}
