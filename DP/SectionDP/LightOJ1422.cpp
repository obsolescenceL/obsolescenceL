/*************************************************************************
     File Name: LightOJ1422.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月19日 星期五 21时16分12秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#define Min(x,y) ((x)<(y)?(x):(y))
#define Mem0(x) memset(x,0,sizeof(x))
using namespace std;
const int N=110;
int a[N],dp[N][N];

int main(){
  int t,nc,n,i,j,k;
  while(~scanf("%d",&t)){
    nc=0;
    while(t--){
      Mem0(dp);
      scanf("%d",&n);
      for(i=0;i<n;++i)scanf("%d",a+i);
      for(i=0;i<n;++i)
        for(j=i;j<n;++j)
          dp[i][j]=j-i+1;
      for(i=n-2;i>=0;--i)
        for(j=i+1;j<n;++j){
          dp[i][j]=dp[i+1][j]+1;//!!!
          for(k=i+1;k<=j;++k)
            if(a[k]==a[i]){
              dp[i][j]=Min(dp[i][j],dp[i+1][k-1]+dp[k][j]);
              //cout<<"dp["<<i+1<<"]["<<j+1<<"]="<<dp[i][j]<<"=dp["<<i+2<<"]["<<k<<"]+dp["<<k+1<<"]["<<j+1<<"]="<<dp[i+1][k-1]<<"+"<<dp[k][j]<<endl;
            }
        }
      printf("Case %d: %d\n",++nc,dp[0][n-1]);
    }
  }
}
