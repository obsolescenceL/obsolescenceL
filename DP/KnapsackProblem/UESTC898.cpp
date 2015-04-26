/*************************************************************************
     File Name: d.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月25日 星期六 22时50分22秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define Mem0(x) memset(x,0,sizeof(x))
const int N=128;
int card[17],dp[17][N][N];

int main(){
  int n,i,j,k,ans;
  while(~scanf("%d",&n)){
    Mem0(dp);ans=0;
    for(i=1;i<=n;++i)
      scanf("%d",card+i);
    dp[0][0][0]=1;
    for(i=1;i<=n;++i)
      for(j=0;j<N;++j)
        for(k=0;k<N;++k){
          dp[i][j][k]+=dp[i-1][j][k];
          dp[i][card[i]^j][k]+=dp[i-1][j][k];
          dp[i][j][card[i]^k]+=dp[i-1][j][k];
        }
    for(i=0;i<N;++i)
      for(j=0;j<=i;++j)
        ans+=dp[n][i][j];
    printf("%d\n",ans);
  }
}
