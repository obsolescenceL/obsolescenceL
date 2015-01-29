/*************************************************************************
     File Name: cf.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月28日  0:52:10
 ************************************************************************/
#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=310;
int m,t,r,c[MAXN],g[MAXN],x,i,j,k,flag=1,cnt;
bool vis[MAXN];
int main(){
  scanf("%d%d%d",&m,&t,&r);
  for(i=1;i<=m;i++)scanf("%d",&x),g[x]=1;
  if(t<r){
    puts("-1");
    return 0;
  }
  for(i=1;i<MAXN;i++){
    if(g[i]&&flag){
      flag=0,cnt=k=r;
      for(j=i;j<i+t;j++){
        if(j>i+t-r)k--;
        c[j]=k;
      }
    }
    for(j=i-1;g[i]&&c[i]<r;j--)
      if(!vis[j]){
        vis[j]=1,cnt++;
        for(k=j+1;k<=j+t;k++)c[k]++;
      }
  }
  printf("%d\n",cnt);
}
