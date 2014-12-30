#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1010;
int dp[MAXN][MAXN];
char a[MAXN],b[MAXN];
int LCS(int n,int m){
  int len=max(n,m),i,j;
  for(i=0;i<=len;i++)dp[i][0]=0,dp[0][i]=0;
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++){
      if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1]+1;
      else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }
}
void print_LCS(int i,int j){
  if(!i||!j);
  else if(a[i-1]==b[j-1]){
    print_LCS(i-1,j-1);
    printf("%c",a[i-1]);
  }
  else if(dp[i-1][j]>dp[i][j-1])print_LCS(i-1,j);
  else print_LCS(i,j-1);
}
int main(){
  while(gets(a)&&gets(b)){
    int n=strlen(a);
    int m=strlen(b);
    sort(a,a+n);
    sort(b,b+m);
    LCS(n,m);
    print_LCS(n,m);
    puts("");
  }
}
