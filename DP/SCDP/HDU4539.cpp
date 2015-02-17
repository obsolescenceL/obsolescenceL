/*************************************************************************
     File Name: HDU4539.cpp
     ID: obsolescence
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月17日 11:17:00
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int state[210],num[210],dp[2][210][210],mark[110];

inline int count(int x){
  int cnt=0;
  while(x){
    cnt++;x&=x-1;
  }
  return cnt;
}

int main(){
  int n,m,i,j,t,k,mp;
  while(~scanf("%d%d",&n,&m)){
    int ans=0,top=0;
    for(i=0;i<1<<m;++i)
      if(!(i&i<<2))state[++top]=i;
    memset(dp,-1,sizeof dp);
    memset(mark,0,sizeof mark);
    for(i=1;i<=n;++i)
      for(j=1;j<=m;++j){
        scanf("%d",&mp);
        if(!mp)mark[i]|=(1<<(j-1));
      }
    for(i=1;i<=top;++i){
      num[i]=count(state[i]);
      if(state[i]&mark[1])continue;
      dp[1][i][1]=num[i];
    }
    for(i=2;i<=n;++i)
      for(t=1;t<=top;++t){
        if(state[t]&mark[i])continue;
        for(j=1;j<=top;++j){
          if(state[t]&(state[j]<<1))continue;
          if(state[t]&(state[j]>>1))continue;
          for(k=1;k<=top;++k){
            if(state[t]&state[k])continue;
            if(state[j]&(state[k]<<1))continue;
            if(state[j]&(state[k]>>1))continue;
            if(dp[(i-1)&1][j][k]==-1)continue;
            dp[i&1][t][j]=max(dp[i&1][t][j],dp[(i-1)&1][j][k]+num[t]);
          }
        }
      }
    for(j=1;j<=top;++j)
      for(k=1;k<=top;++k)
        ans=max(ans,dp[n&1][j][k]);
    printf("%d\n",ans);
  }
}
