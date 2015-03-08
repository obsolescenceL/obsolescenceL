/*************************************************************************
     File Name: UVA562.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月08日 星期日 21时41分52秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int coins[110],dp[50010];

int main(){
  int n,m,i,j,sum;
  while(~scanf("%d",&n)){
    while(n--){
      sum=0;
      memset(dp,0,sizeof dp);
      scanf("%d",&m);
      for(i=0;i<m;++i)scanf("%d",coins+i),sum+=coins[i];
      int mid=sum/2;
      for(i=0;i<m;++i)
        for(j=mid;j>=coins[i];--j){
          dp[j]=max(dp[j],dp[j-coins[i]]+coins[i]);
        }
      printf("%d\n",sum-2*dp[mid]);
    }
  }
}
