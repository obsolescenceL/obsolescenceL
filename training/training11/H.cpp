/*************************************************************************
     File Name: H.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月29日 星期三 12时16分43秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>
#include<bitset>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=1010,INF=0x3f3f3f3f;
int dp[N][N];

int main(){
  int t,i,n,m,j,nc;
  while(~scanf("%d",&t)){
    for(nc=1;nc<=t;++nc){
      scanf("%d%d",&n,&m);
      for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
          scanf("%d",&dp[i][j]);
          dp[n+1][j]=-INF;
          //cout<<"dp["<<n+1<<"]["<<i<<"]="<<dp[n+1][i]<<endl;
        }
        dp[i][m+1]=-INF;
      }
      //cout<<"dp[2][2]="<<dp[2][2]<<endl;
      for(i=n;i;--i){
        for(j=m;j;--j){
          //cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
          if(i==n&&j==m)continue;
          dp[i][j]+=Max(dp[i+1][j],dp[i][j+1]);
          //cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
        }
      }
      printf("Case %d: %d\n",nc,dp[1][1]);
    }
  }
}
