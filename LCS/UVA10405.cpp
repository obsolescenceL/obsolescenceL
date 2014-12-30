#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1010;
int dp[2][MAXN];
string a,b;
int LCS(int n,int m){
  int len=max(n,m);
  for(int i=0;i<=len;i++)dp[0][i]=0,dp[i%2][0]=0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      if(a[i-1]==b[j-1])dp[i%2][j]=dp[(i-1)%2][j-1]+1;
      else dp[i%2][j]=max(dp[i%2][j-1],dp[(i-1)%2][j]);
    }
  return dp[n%2][m];
}
int main(){
  while(getline(cin,a)&&getline(cin,b)){
    printf("%d\n",LCS(a.size(),b.size()));
  }
}
