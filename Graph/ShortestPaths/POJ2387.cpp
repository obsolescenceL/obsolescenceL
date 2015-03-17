/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月11日 星期三 14时27分41秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3F3F3F3F;
int adj[1010][1010],dis[1010];
bool vis[1010];

int main(){
  int n,m,x,y,len,i,j,k;
  while(~scanf("%d%d",&m,&n)){
    memset(adj,0x3F,sizeof adj);
    memset(vis,0,sizeof vis);
    while(m--)scanf("%d%d%d",&x,&y,&len),adj[x][y]=adj[y][x]=min(adj[x][y],len);
    adj[1][1]=0;
    for(i=1;i<=n;++i)dis[i]=adj[1][i];
    vis[1]=1;
    for(i=1;i<n;++i){
      int temp=INF,k=1;
      for(j=1;j<=n;++j){
        if(vis[j])continue;
        if(temp>dis[j]){
          temp=dis[j];
          k=j;
        }
      }
      vis[k]=j;
      for(j=1;j<=n;++j){
        if(vis[j])continue;
        dis[j]=min(dis[j],dis[k]+adj[k][j]);
      }
    }
    printf("%d\n",dis[n]);
  }
}
