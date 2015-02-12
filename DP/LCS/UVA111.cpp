/*************************************************************************
    > File Name: UVA111.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2014年12月31日 16:31:24
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=110;
int dp[MAXN][MAXN];
char a[MAXN],b[MAXN];
int lcs(int n){
  int i,j;
  for(i=0;i<=n;i++)dp[i][0]=0,dp[0][i]=0;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
      if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
      else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }
  return dp[n][n];
}
int main(){
  int i,n,c,d;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&c);
    a[c]=i;
  }
  while(~scanf("%d",&d)){
    b[d]=1;
    for(i=2;i<=n;i++){
      scanf("%d",&d);
      b[d]=i;
    }
    printf("%d\n",lcs(n));
  }
}
