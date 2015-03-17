/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月14日 星期六 09时28分23秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[100000],va[20],vo[20];

int main(){
  int t,num,n,m,i,j;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d%d",&num,&n,&m);
      for(i=0;i<m;++i)scanf("%d%d",vo+i,va+i),vo[i]/=1000;
      while(n--){
        memset(dp,0,sizeof dp);
        for(i=0;i<m;++i)
          for(j=vo[i];j<=num/1000;++j)
            dp[j]=max(dp[j],dp[j-vo[i]]+va[i]);
        num+=dp[num/1000];
      }
      printf("%d\n",num);
    }
  }
}
