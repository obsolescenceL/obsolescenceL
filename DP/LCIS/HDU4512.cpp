/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月07日 星期六 14时06分39秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int h[210],rh[210],dp[210];

int main(){
  int t,n,i,j,len,ans;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&n);
      for(i=0;i<n;++i)scanf("%d",h+i),rh[i]=h[i];
      reverse(rh,rh+n);
      ans=0;
      memset(dp,0,sizeof dp);
      for(i=1;i<=n;++i){
        len=0;
        for(j=1;j<=n+1-i;++j){
          if(h[i-1]>rh[j-1])len=max(len,dp[j]);
          if(h[i-1]==rh[j-1])dp[j]=len+1;
          if(j==n+1-i)ans=max(ans,dp[j]*2-1);
          else ans=max(ans,dp[j]*2);
        }
      }
      printf("%d\n",ans);
    }
  }
}
