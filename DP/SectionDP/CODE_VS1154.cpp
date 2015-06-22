/*************************************************************************
     File Name: CODE_VS1154.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月22日 星期一 10时21分33秒
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
const int N=210;
ll dp[N][N];
int temp[N];
struct node{
  ll l,r;
}w[N];

int main(){
  int n,i,j,k;
  while(~scanf("%d",&n)){
    for(i=1;i<=n;++i)
      scanf("%d",temp+i);
    ll maxn=0,nn=n<<1;
    Mem0(dp);
    for(i=1;i<n;++i)
      w[i].r=w[i+n].r=temp[i+1];
    w[n].r=w[1].l=temp[1];
    for(i=2;i<=nn;++i)
      w[i].l=w[i-1].r;
    for(i=nn-2;i;--i)
      for(j=i+1;j<nn;++j)
        for(k=i;k<j;++k)
          dp[i][j]=Max(dp[i][j],dp[i][k]+dp[k+1][j]+w[i].l*w[k].r*w[j].r);
    for(i=1;i<=n;++i)
      maxn=Max(maxn,dp[i][i+n-1]);
    printf("%lld\n",maxn);
  }
}
