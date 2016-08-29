/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  8/29 21:22:01 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=60;
LL dp[N][N*N];
int x[N];

int main() {
  int n,m,i,j,k,tmp;
  ios::sync_with_stdio(0);
  while (cin>>n>>m) {
    for (i=1; i<=n; ++i) cin>>x[i];
    MEM1(dp);
    dp[0][0]=1;
    for (k=1,tmp=0; k<=n; ++k) {
      tmp+=x[k];
      for (i=k; i>=1; --i)
        for (j=tmp; j>=x[k]; --j) {
          if (dp[i-1][j-x[k]] == -1) continue;
          if (dp[i][j] == -1) dp[i][j]=0;
          dp[i][j]+=dp[i-1][j-x[k]];
        }
    }
    LL ans=0;
    for (i=1; i<=n; ++i)
      if (dp[i][i*m] != -1)
        ans+=dp[i][i*m];
    cout<<ans<<endl;
  }
}
