/*************************************************************************
    > File Name: UVA531.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2014年12月31日 15:27:06
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[110][110],f;
char a[110][40],b[110][40];
void lcs(int n,int m){
  int i,j,len=max(n,m);
  for(i=0;i<=len;i++)dp[i][0]=0,dp[0][i]=0;
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++){
      if(strcmp(a[i-1],b[j-1])==0)dp[i][j]=dp[i-1][j-1]+1;
      else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }
}
void print_lcs(int i,int j){
  if(!i||!j);
  else if(strcmp(a[i-1],b[j-1])==0){
    print_lcs(i-1,j-1);
    if(f){
      printf("%s",a[i-1]);
      f=0;
    }else printf(" %s",a[i-1]);
  }else if(dp[i][j-1]>dp[i-1][j])print_lcs(i,j-1);
  else print_lcs(i-1,j);
}
int main(){
  int i,j;
  while(~scanf("%s",a[0])){
    i=1; j=0; f=1;
    while(scanf("%s",a[i])){
      if(strcmp(a[i++],"#")==0)break;
    }
    while(scanf("%s",b[j])){
      if(strcmp(b[j++],"#")==0)break;
    }
    lcs(i-1,j-1);
    print_lcs(i-1,j-1);
    puts("");
  }
}
