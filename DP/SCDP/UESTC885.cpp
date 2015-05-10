/*************************************************************************
     File Name: UESTC885.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月10日 星期日 14时26分19秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
ll n,m,dp[20][3000];

void dfs(ll sum,ll k,ll a,ll b,ll pos){
  if(a==(1<<m)-1){
    dp[k+1][b]+=sum;
    return;
  }
  int i=pos;
  if(!(a&(1<<i))){
    dfs(sum,k,a|(1<<i),b|(1<<i),pos+1);
    if(i<m-1 && !(a&(2<<i)))
      dfs(sum,k,a|(3<<i),b,pos+2);
  }
  else dfs(sum,k,a,b,pos+1);
}

int main(){
  ll i,j;
  while(~scanf("%lld%lld",&n,&m)){
    if((n*m)%2){
      puts("0");
      continue;
    }
    Mem0(dp);
    dp[0][0]=1;
    for(i=0;i<n;++i)
      for(j=0;j<(1<<m);++j)
        if(dp[i][j])dfs(dp[i][j],i,j,0,0);
    printf("%lld\n",dp[n][0]);
  }
}
