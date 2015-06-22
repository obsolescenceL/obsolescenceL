/*************************************************************************
     File Name: CODE_VS1048.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月21日 星期日 18时50分45秒
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
const int N=110,INF=0x3f3f3f3f;
int dp[N][N],w[N],t[N][N];

int main(){
  int n,i,j,k;
  while(~scanf("%d",&n)){
    MemX(dp),Mem0(t);
    int nn=n<<1,minn=INF;
    for(i=1;i<=n;++i)
      scanf("%d",w+i);
    for(i=1;i<=n;++i){
      t[i][i]=w[i];
      dp[i][i]=0;
      for(j=i+1;j<=n;++j)
        t[i][j]=t[i][j-1]+w[j];
    }
    for(i=n-1;i;--i)
      for(j=i+1;j<=n;++j)
        for(k=i;k<=j-1;++k)
          dp[i][j]=Min(dp[i][j],dp[i][k]+dp[k+1][j]+t[i][j]);
    printf("%d\n",dp[1][n]);
  }
}
