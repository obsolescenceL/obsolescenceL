/*************************************************************************
     File Name: f.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月15日 星期日 18时23分25秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int mod=100000007;
int a[55],c[55];
int dp[1005];

int main(){
  int t,n,k,i,j,l;
  int ncase;
  while(~scanf("%d",&t)){
    for(ncase=1;ncase<=t;++ncase){
      scanf("%d%d",&n,&k);
      for(i=1;i<=n;++i)scanf("%d",a+i);
      for(i=1;i<=n;++i)scanf("%d",c+i);
      memset(dp,0,sizeof dp);
      dp[0]=1;
      for(i=1;i<=n;++i){
        for(j=k;j>=0;--j)
          for(l=1;l<=c[i];++l)
            if(j-l*a[i]>=0)
              dp[j]+=dp[j-l*a[i]];
        for(j=0;j<=k;++j)
          dp[j]%=mod;
      }
      printf("Case %d: %d\n",ncase,dp[k]);
    }
  }
}
