/*************************************************************************
     File Name: UESTC876.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月09日 星期六 23时33分32秒
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
ll zhi[25],dp[25][25];

int main(){
  int t,n,m,i,j,k;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d",&n,&m);
      for(i=1;i<=n;++i)
        scanf("%lld",zhi+i),zhi[i]+=zhi[i-1];
      for(i=1;i<=n;++i)dp[1][i]=zhi[i];
      for(i=2;i<=m;++i)
        for(j=i;j<=n;++j){
          dp[i][j]=dp[i-1][1]*(zhi[j]-zhi[1]);
          for(k=1;k<j;++k)
            dp[i][j]=Max(dp[i][j],dp[i-1][k]*(zhi[j]-zhi[k]));
        }
      printf("%lld\n",dp[m][n]);
    }
  }
}
