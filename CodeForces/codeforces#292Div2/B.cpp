/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月27日 星期五 09时51分05秒
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
int hb[110],hg[110],vb[110],vg[110];

int main(){
  int n,m,b,g,i;
  while(~scanf("%d%d",&n,&m)){
    memset(vb,0,sizeof vb);
    memset(vg,0,sizeof vg);
    scanf("%d",&b);
    for(i=0;i<b;++i){
      scanf("%d",hb+i);
      vb[hb[i]]=1;
    }
    scanf("%d",&g);
    for(i=0;i<g;++i){
      scanf("%d",hg+i);
      vg[hg[i]]=1;
    }
    //for(i=0;i<n;++i)cout<<vb[i]<<' ';
    for(i=0;i<=4*n*m;++i){
      if(vb[i%n]||vg[i%m])vb[i%n]=vg[i%m]=1;
    }
    //for(i=0;i<n;++i)cout<<vb[i]<<' ';
    bool flag=1;
    for(i=0;i<n&&flag;++i){
      if(!vb[i])flag=0;
    }
    for(i=0;i<m&&flag;++i){
      if(!vg[i])flag=0;
    }
    if(!flag)puts("No");
    else puts("Yes");
  }
}
