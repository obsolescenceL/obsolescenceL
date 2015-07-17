/*************************************************************************
     File Name: POJ1141.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月16日 星期四 20时38分41秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define Max(x,y) ((x)>(y)?(x):(y))
const int N=110,INF=0x3f3f3f3f;
int dp[N][N];
char s[N];

int check(int lhs,int rhs){
  if(s[lhs]=='('&&s[rhs]==')')return 1;
  if(s[lhs]=='['&&s[rhs]==']')return 1;
  return 0;
}

void print(int i,int j){
  if(i>j)return;
  if(i==j){
    if(s[i]=='(' || s[i]==')')
      printf("()");
    else printf("[]");
  }else if(check(i,j)&&dp[i][j]==dp[i+1][j-1]+1){
    printf("%c",s[i]);
    print(i+1,j-1);
    printf("%c",s[j]);
  }else{
    for(int k=i;k<j;++k)
      if(dp[i][k]+dp[k+1][j]==dp[i][j]){
        print(i,k);
        print(k+1,j);
        break;
      }
  }
}

int main(){
  int i,j,k,len;
  scanf("%s",s);
  len=strlen(s);
  for(i=len-2;i>=0;--i)
    for(j=i+1;j<len;++j){
      dp[i][j]=dp[i+1][j-1]+check(i,j);
      for(k=i;k<j;++k)
        dp[i][j]=Max(dp[i][j],dp[i][k]+dp[k+1][j]);
    }
  print(0,len-1);
  puts("");
}
