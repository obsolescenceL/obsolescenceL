#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=110;
int a[MAXN],b[MAXN],dp[2][MAXN],n,m;
int lcs(){
  int i,j,len=max(n,m);
  for(i=0;i<=len;i++)dp[i%2][0]=0,dp[0][i]=0;
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++){
      if(a[i]==b[j])dp[i%2][j]=dp[(i-1)%2][j-1]+1;
      else dp[i%2][j]=max(dp[i%2][j-1],dp[(i-1)%2][j]);
    }
  return dp[n%2][m];
}
int main(){
  int k=0;
  while(~scanf("%d%d",&n,&m)&&n||m){
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=m;i++)scanf("%d",b+i);
    printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",++k,lcs());
  }
}
