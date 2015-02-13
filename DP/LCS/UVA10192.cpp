#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=110;
int dp[2][MAXN];
string a,b;
int lcs(int n,int m){
  int i,j,len=max(n,m);
  for(i=0;i<=len;i++)dp[i%2][0]=0,dp[0][i]=0;
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++){
      if(a[i-1]==b[j-1])dp[i%2][j]=dp[(i-1)%2][j-1]+1;
      else dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
    }
  return dp[n%2][m];
}
int main(){
  int k=0;
  while(getline(cin,a)){
    if(a[0]=='#')break;
    getline(cin,b);
    printf("Case #%d: you can visit at most %d cities.\n",++k,lcs(a.size(),b.size()));
  }
}
