/*************************************************************************
     File Name: POJ3661.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月11日 星期六 10时04分44秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Mem0(x) memset(x,0,sizeof(x))
const int N=10010,M=510;
int dp[N][M];

int main(){
  int n,m,a,i,j,k;
  while(~scanf("%d%d",&n,&m)){
    Mem0(dp);
    for(i=1;i<=n;++i){
      scanf("%d",&a);
      dp[i][0]=dp[i-1][0];
      for(j=1;j<=m;++j){
        if(j<i)dp[i][0]=Max(dp[i][0],dp[i-j][j]);
        dp[i][j]=dp[i-1][j-1]+a;
      }
    }
    printf("%d\n",dp[n][0]);
  }
}
