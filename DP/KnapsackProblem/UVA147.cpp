/*************************************************************************
     File Name: c.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月13日 星期五 15时47分36秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
using namespace std;
const int M=30005/5;
int coin[]={1,2,4,10,20,40,100,200,400,1000,2000};
long long dp[M];

int main(){
  int i,j;
  double n;
  dp[0]=1;
  for(i=0;i<11;++i)
    for(j=coin[i];j<=M;++j)
      if(j>=coin[i])
        dp[j]+=dp[j-coin[i]];
  while(~scanf("%lf",&n)){
    int ans=20*n+0.5;
    if(ans)printf("%6.2lf%17lld\n",n,dp[ans]);
  }
}
