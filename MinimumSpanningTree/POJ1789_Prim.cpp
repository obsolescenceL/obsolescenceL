/*************************************************************************
     File Name: POJ1789_Prim.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月21日 14:20:37
 ************************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<iostream>
#include<cctype>
#include<climits>
const int MAXN=2010,INF=0x3F3F3F3F;
using namespace std;
char a[MAXN][10];
int adj[MAXN][MAXN],d[MAXN],n;
bool vis[MAXN];

void Prim(){
  int i,j,sum=0;
  memset(vis,0,sizeof vis);
  memset(d,0x3F,sizeof d);
  d[0]=0;
  for(i=0;i<n;++i){
    int a=-1,minn=INF;
    for(j=0;j<n;++j){
      if(!vis[j]&&d[j]<minn)
        a=j,minn=d[j];
    }
    if(a==-1)break;
    vis[a]=1;
    sum+=d[a];
    for(j=0;j<n;++j)
      if(adj[a][j]&&!vis[j]&&adj[a][j]<d[j])
        d[j]=adj[a][j];
  }
  printf("The highest possible quality is 1/%d.\n",sum);
}

int main(){
  int dis,i,j,k;
  while(~scanf("%d",&n)&&n){
    memset(adj,0,sizeof adj);
    for(i=0;i<n;++i){
      scanf("%s",a[i]);
      for(j=0;j<i;++j){
        dis=0;
        for(k=0;k<7;++k){
          if(a[i][k]!=a[j][k])dis++;
        }
        adj[i][j]=adj[j][i]=dis;
      }
    }
    Prim();
  }
}
