/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月20日 星期三 14时08分24秒
 ************************************************************************/
#include<bits/stdc++.h>
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
const int N=510,INF=0x3f3f3f3f;
int mp[N][N],dp[N][N];

int main(){
  int T,n,m,i,j;
  while(~scanf("%d",&T)){
    while(T--){
      scanf("%d%d",&n,&m);
      for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
          scanf("%d",&mp[i][j]);
      dp[n][m]=1;
      for(i=n-1;i>=1;--i){
        dp[i][m]=Max(1,dp[i+1][m]-mp[i+1][m]);
        //cout<<"dp["<<i<<"]["<<m<<"]="<<dp[i][m]<<endl;
      }
      for(j=m-1;j>=1;--j){
        dp[n][j]=Max(1,dp[n][j+1]-mp[n][j+1]);
        //cout<<"dp["<<n<<"]["<<j<<"]="<<dp[n][j]<<endl;
      }
      for(i=n-1;i>=1;--i)
        for(j=m-1;j>=1;--j)
          dp[i][j]=Max(1,Min(dp[i][j+1]-mp[i][j+1],dp[i+1][j]-mp[i+1][j]));
      printf("%d\n",dp[1][1]);
    }
  }
}
