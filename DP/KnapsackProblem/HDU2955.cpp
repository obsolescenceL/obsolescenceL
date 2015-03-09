/*************************************************************************
     File Name: HDU2955.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月09日 星期一 15时06分00秒
 ************************************************************************/
#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
double p[110],dp[10010];
int v[110];

int main(){
  int t,n,i,j,sum;
  double m;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%lf%d",&m,&n);
      sum=0;
      //printf("minp=%lf\n",minp);
      for(i=0;i<n;++i)scanf("%d%lf",v+i,p+i),sum+=v[i];
      memset(dp,0,sizeof dp);
      //for(i=0;i<=sum;++i)dp[i]=1;
      dp[0]=1;
      for(i=0;i<n;++i)
        for(j=sum;j>=v[i];--j)
          dp[j]=max(dp[j],dp[j-v[i]]*(1-p[i]));
      for(i=sum;i>=0;--i)
        if(dp[i]>1-m){
          printf("%d\n",i);
          break;
        }
    }
  }
}
