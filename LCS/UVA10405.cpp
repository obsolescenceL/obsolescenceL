#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1010;
int dp[MAXN][MAXN];
string a,b;
int LCS(int n,int m){
  int len=max(n,m);
  for(int i=0;i<=len;i++)dp[0][i]=0,dp[i][0]=0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1]+1;
      else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }
  return dp[n][m];
}
int main(){
  while(getline(cin,a)&&getline(cin,b)){
    printf("%d\n",LCS(a.size(),b.size()));
  }
}
