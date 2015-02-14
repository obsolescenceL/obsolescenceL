/*************************************************************************
     File Name: POJ3254.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月13日 16:15:23
 ************************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<iostream>
#include<cctype>
using namespace std;
const int mod=1e8;
int state[1<<12],mark[15],dp[15][1<<12];

int main(){
  int n,m,i,j,k,top,num,ans;
  while(~scanf("%d%d",&n,&m)){
    top=ans=0;
    for(i=0;i<1<<m;++i){
      if(!(i&i<<1))state[++top]=i;
    }
    memset(dp,0,sizeof dp);
    memset(mark,0,sizeof mark);
    for(i=1;i<=n;++i){
      for(j=1;j<=m;++j){
        scanf("%d",&num);
        if(!num)mark[i]+=(1<<(m-j));
      }
    }
    for(i=1;i<=top;++i)
      if(!(state[i]&mark[1]))dp[1][i]=1;
    for(i=2;i<=n;++i){
      for(k=1;k<=top;++k){
        if(state[k]&mark[i])continue;
        for(j=1;j<=top;++j){
          if(state[j]&mark[i-1])continue;
          if(state[j]&state[k])continue;
          dp[i][k]=(dp[i][k]+dp[i-1][j])%mod;
        }
      }
    }
    for(i=1;i<=top;++i){
      ans=(ans+dp[n][i])%mod;
    }
    printf("%d\n",ans);
  }
}
