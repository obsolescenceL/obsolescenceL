/*************************************************************************
     File Name: UVA624.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月04日 星期三 22时03分30秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int cdNumber=25;
const int maxTime=10000;
int v[cdNumber],dp[maxTime],path[cdNumber][maxTime];

int main(){
  int n,m,i,j,ans,x,y;
  while(~scanf("%d%d",&m,&n)){
    for(i=1;i<=n;++i){
      scanf("%d",v+i);
    }
    memset(dp,0,sizeof dp);
    memset(path,0,sizeof path);
    for(i=n;i;--i)
      for(j=m;j>=v[i];--j){
        if(dp[j]<dp[j-v[i]]+v[i]){
          dp[j]=dp[j-v[i]]+v[i];
          path[i][j]=1;
        }
        //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
      }
//    for(i=n;i;--i)
//      for(j=m;j;--j)
//        if(ans<dp[i][j]){
//          ans=dp[i][j];
//          x=i;
//          y=j;
//        }
//    for(x=n;x;--x){
//      if(dp[x][y]>dp[x-1][y])y-=v[x],printf("%d ",v[x]);
//    }
    //if(j)printf("%d ",v[0]);
    for(i=1,j=m;i<=n;++i)
      if(path[i][j])printf("%d ",v[i]),j-=v[i];
    printf("sum:%d\n",dp[m]);
  }
}
