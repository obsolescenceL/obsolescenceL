/*************************************************************************
     File Name: HDU1863_Prim.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月26日 20:29:55
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100;
int d[MAXN],adj[MAXN][MAXN];
bool vis[MAXN];
int n,m;

void Prim(){
  int i,sum=0;
  memset(vis,0,sizeof vis);
  memset(d,0x3F,sizeof d);
  d[1]=0;
  for(i=0;i<m;i++){
    int a=-1,minn=1e9;
    for(int j=1;j<=m;j++)
      if(!vis[j]&&d[j]<minn){
        a=j;
        minn=d[j];
      }
    if(a==-1)break;
    vis[a]=1;
    sum+=d[a];
    for(int j=1;j<=m;j++)
      if(adj[a][j]&&!vis[j]&&adj[a][j]<d[j]){
        d[j]=adj[a][j];
      }
  }
  i==m?printf("%d\n",sum):puts("?");
}

int main(){
  int a,b,c;
  while(~scanf("%d%d",&n,&m)&&n){
    memset(adj,0,sizeof adj);
    for(int i=0;i<n;i++){
      scanf("%d%d%d",&a,&b,&c);
      adj[a][b]=c, adj[b][a]=c;
    }
    Prim();
  }
}
