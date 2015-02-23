/*************************************************************************
     File Name: HDU3790.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月23日 15:13:43
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
using namespace std;
const int INF=0x3F3F3F3F;
struct node{
  int d,p;
}dis[1010],adj[1010][1010];
bool vis[1010];

int main(){
  int n,m,a,b,d,p,i,j,s,t;
  while(~scanf("%d%d",&n,&m)&&(n||m)){
    memset(adj,0x3F,sizeof adj);
    //cout<<adj[1][1].p<<' '<<adj[1][1].d<<endl;
    memset(vis,0,sizeof vis);
    while(m--){
      scanf("%d%d%d%d",&a,&b,&d,&p);
      if(adj[a][b].d>d){
        adj[a][b].d=adj[b][a].d=d;
        adj[a][b].p=adj[b][a].p=p;
      }else if(adj[a][b].d==d){
        adj[a][b].p=adj[b][a].p=min(adj[a][b].p,p);
      }
    }
    scanf("%d%d",&s,&t);
    for(i=1;i<=n;++i)
      dis[i].d=adj[s][i].d,dis[i].p=adj[s][i].p;
    vis[s]=1;
    for(i=1;i<n;++i){
      int temp=INF,k=s;
      for(j=1;j<=n;++j){
        if(vis[j])continue;
        if(temp>dis[j].d)
          temp=dis[j].d,k=j;
      }
      vis[k]=1;
      for(j=1;j<=n;++j){
        if(vis[j])continue;
        if(dis[j].d>dis[k].d+adj[k][j].d)
          dis[j].d=dis[k].d+adj[k][j].d,dis[j].p=dis[k].p+adj[k][j].p;
        else if(dis[j].d==dis[k].d+adj[k][j].d)
          dis[j].p=dis[k].p+adj[k][j].p;
      }
    }
    //for(i=1;i<=n;++i) printf("dis[%d].d=%d dis[%d].p=%d\n",i,dis[i].d,i,dis[i].p);
    printf("%d %d\n",dis[t].d,dis[t].p);
  }
}
