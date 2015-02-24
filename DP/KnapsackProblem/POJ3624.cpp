/*************************************************************************
     File Name: POJ3624.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月24日 18:58:00
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
#include<climits>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int INF=0x3F3F3F3F;
int w[3405],d[3405],dp[12900];

int main(){
  int n,m,i,j,ans;
  while(~scanf("%d%d",&n,&m)){
    for(i=1;i<=n;++i){
      scanf("%d%d",w+i,d+i);
    }
    memset(dp,0,sizeof dp);
    ans=0;
    for(i=1;i<=n;++i)
      for(j=m;j>=w[i];--j){
        dp[j]=Max(dp[j],dp[j-w[i]]+d[i]);
        ans=Max(ans,dp[j]);
      }
    printf("%d\n",ans);
  }
}
