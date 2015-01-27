/*************************************************************************
     File Name: HDU1233_Prim.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月27日 11:41:45
 ************************************************************************/
#include<cstdio>
#include<cstring>
using namespace std;
const int INF=0x3F3F3F3F,MAXN=100;
bool vis[MAXN];
int adj[MAXN][MAXN],n,m,d[MAXN];

inline void Prim(){
  memset(vis,0,sizeof vis);
  memset(d,0x3F,sizeof d);
  int i,j,sum=0;
  d[1]=0;
  for(i=1;i<=n;i++){
    int a=-1,minn=INF;
    for(j=1;j<=n;j++)
      if(!vis[j] && d[j]<minn)
        a=j,minn=d[j];
    if(a==-1)break;
    vis[a]=1;
    sum+=minn;
    //cout<<"sum="<<sum<<endl;
    for(j=1;j<=n;j++)
      if(adj[a][j] && !vis[j] && adj[a][j]<d[j])
        d[j]=adj[a][j];
  }
  printf("%d\n",sum);
}

int main(){
  int a,b,c;
  while(~scanf("%d",&n)&&n){
    memset(adj,0,sizeof adj);
    m=n*(n-1)/2;
    for(int i=1;i<=m;i++){
      scanf("%d%d%d",&a,&b,&c);
      adj[a][b]=c,adj[b][a]=c;
    }
    Prim();
  }
}
