/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月07日 星期六 16时35分51秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3F3F3F3F;
int dis[301][301];

int main(){
  int n,m,t,i,x,y,s,e,j,k;
  while(~scanf("%d%d%d",&n,&m,&t)){
    memset(dis,0x3F,sizeof dis);
    for(i=0;i<m;++i)scanf("%d%d%d",&x,&y,&s),dis[x][y]=min(dis[x][y],s);
    for(k=1;k<=n;++k)
      for(i=1;i<=n;++i)
        for(j=1;j<=n;++j){
          int w=max(dis[i][k],dis[k][j]);
          dis[i][j]=min(dis[i][j],w);
        }
    while(t--){
      scanf("%d%d",&s,&e);
      if(dis[s][e]==INF)puts("-1");
      else printf("%d\n",dis[s][e]);
    }
  }
}
