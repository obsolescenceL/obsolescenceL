/*************************************************************************
     File Name: POJ1185.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月13日 16:47:47
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
int state[70],num[70],dp[110][70][70],mark[110];
char mp[110][15];

inline int count(int x){
  int cnt=0;
  while(x){
    cnt++;
    x&=x-1;
  }
  return cnt;
}

int main(){
  int n,m,i,j,t,k;
  while(~scanf("%d%d",&n,&m)){
    int ans=0,top=0;
    for(i=0;i<1<<m;++i){
      if(!((i&i<<1)||(i&i<<2)))state[++top]=i;
    }
    memset(dp,0,sizeof dp);
    memset(mark,0,sizeof mark);
    for(i=1;i<=n;++i){
      scanf("%s",mp[i]+1);
      for(j=1;j<=m;++j){
        if(mp[i][j]=='H')mark[i]+=1<<(j-1);
      }
    }
    for(i=1;i<=top;++i){
      num[i]=count(state[i]);
      if(!(state[i]&mark[1]))dp[1][1][i]=num[i];
    }
    for(i=2;i<=n;++i){
      for(t=1;t<=top;++t){
        if(state[t]&mark[i])continue;
        for(j=1;j<=top;++j){
          if(state[t]&state[j])continue;
          for(k=1;k<=top;++k){
            if(state[t]&state[k])continue;
            if(!dp[i-1][j][k])continue;
            dp[i][k][t]=max(dp[i][k][t],dp[i-1][j][k]+num[t]);
          }
        }
      }
    }
    for(i=1;i<=n;++i)
      for(j=1;j<=top;++j)
        for(k=1;k<=top;++k)
          ans=max(ans,dp[i][j][k]);
    printf("%d\n",ans);
  }
}
