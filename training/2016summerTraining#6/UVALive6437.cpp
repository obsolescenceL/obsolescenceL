/*************************************************************************
     File Name: D.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月27日 星期三 13时41分52秒
 ************************************************************************/
#include<bits/stdc++.h>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=210,INF=0x3f3f3f3f;
bool vis[N];
int g[N][N],n,m,d[N];

void Prim(){
  Mem0(vis);
  int i,j,sum=0;
  for(i=1;i<=n;++i){
    int a=-1,minn=INF;
    for(j=1;j<=n;++j)
      if(!vis[j] && d[j]<minn)
        a=j,minn=d[j];
    if(a==-1)break;
    vis[a]=1;
    sum+=minn;
    for(j=1;j<=n;++j)
      if(g[a][j] && !vis[j] && g[a][j]<d[j])d[j]=g[a][j];
  }
  printf("%d\n",sum);
}

int main(){
  int t,nc,x,i,k,y,v;
  while(~scanf("%d",&t)){
    nc=0;
    while(t--){
      Mem0(g),MemX(d);
      scanf("%d%d%d",&n,&m,&k);
      while(k--){
        scanf("%d",&x);
        d[x]=0;
      }
      for(i=0;i<m;++i){
        scanf("%d%d%d",&x,&y,&v);
        g[x][y]=g[y][x]=v;
      }
      printf("Case #%d: ",++nc);
      Prim();
    }
  }
}
