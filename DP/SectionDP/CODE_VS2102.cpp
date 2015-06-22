/*************************************************************************
     File Name: CODE_VS2102.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月22日 星期一 09时39分14秒
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
const int N=210,INF=0x3f3f3f3f;
int max_dp[N][N],min_dp[N][N],w[N],t[N][N];

int main(){
  int n,i,j,k;
  while(~scanf("%d",&n)){
    for(i=1;i<=n;++i)
      scanf("%d",w+i),w[i+n]=w[i];
    Mem0(max_dp),MemX(min_dp),Mem0(t);
    int nn=n<<1,maxn=0,minn=INF;
    for(i=1;i<=nn;++i){
      t[i][i]=w[i];
      max_dp[i][i]=min_dp[i][i]=0;
      for(j=i+1;j<=nn;++j)
        t[i][j]=t[i][j-1]+w[j];
    }
    for(i=nn-2;i;--i)
      for(j=i+1;j<nn;++j)
        for(k=i;k<j;++k){
          max_dp[i][j]=Max(max_dp[i][j],max_dp[i][k]+max_dp[k+1][j]+t[i][j]);
          min_dp[i][j]=Min(min_dp[i][j],min_dp[i][k]+min_dp[k+1][j]+t[i][j]);
        }
    for(i=1;i<=n;++i){
      maxn=Max(maxn,max_dp[i][i+n-1]);
      minn=Min(minn,min_dp[i][i+n-1]);
    }
    printf("%d\n%d\n",minn,maxn);
  }
}
