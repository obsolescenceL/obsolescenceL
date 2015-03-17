/*************************************************************************
     File Name: HDU1879_Prim.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月27日 15:04:03
 ************************************************************************/
#include<cstdio>
#include<cstring>
const int INF=0x3F3F3F3F,MAXN=100;
int adj[MAXN][MAXN],n,d[MAXN];
bool vis[MAXN];

inline void Prim(){
  int i,j,sum=0;
  d[1]=0;
  for(i=0;i<n;i++){
    int a=-1,minn=INF;
    for(j=1;j<=n;j++)
      if(!vis[j] && d[j]<minn)
        a=j,minn=d[j];
    if(a==-1)break;
    vis[a]=1;
    sum+=minn;
    for(j=1;j<=n;j++)
      if(adj[a][j]!=-1 && !vis[j] && adj[a][j]<d[j])
        d[j]=adj[a][j];
  }
  printf("%d\n",sum);
}

int main(){
  int a,b,c,i,flag;
  while(~scanf("%d",&n)&&n){
    memset(vis,0,sizeof vis);
    memset(adj,-1,sizeof adj);
    memset(d,0x3F,sizeof d);
    for(i=1;i<=n*(n-1)/2;i++){
      scanf("%d%d%d%d",&a,&b,&c,&flag);
      adj[a][b]=c,adj[b][a]=c;
      if(flag)adj[a][b]=0,adj[b][a]=0;
    }
    Prim();
  }
}
