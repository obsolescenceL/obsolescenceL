/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月22日 星期六 19时18分39秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<iostream>
#include<cctype>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define MemX(x) memset(x,0x3f,sizeof(x))
using namespace std;
const int N=16,INF=0x3f3f3f3f;
int dp[1<<N][N],dis[N][N];

int main(){
  int t,n,m,i,j,k,u,v,w;
  while(~scanf("%d",&t)){
    while(t--){
      MemX(dis),MemX(dp);
      scanf("%d%d",&n,&m);
      while(m--){
        scanf("%d%d%d",&u,&v,&w);
        u--,v--;
        dis[u][v]=dis[v][u]=Min(dis[u][v],w);
      }
      if(n==1){puts("0");continue;}
      for(k=0;k<n;++k)
        for(i=0;i<n;++i)
          for(j=0;j<n;++j)
            dis[i][j]=Min(dis[i][j],dis[i][k]+dis[k][j]);
      m=1<<n;
      for(i=0;i<n;++i)
        dp[1<<i][i]=dis[0][i];
      for(i=1;i<m;++i)
        for(j=0;j<n;++j)
          if(i&(1<<j)){
            int tmp=i^(1<<j);
            for(k=0;k<n;++k)
              if(tmp&(1<<k) && j!=k && dp[tmp][k]<INF)
                dp[i][j]=Min(dp[i][j],dp[tmp][k]+dis[k][j]);
          }
      printf("%d\n",dp[m-1][0]);
    }
  }
}
