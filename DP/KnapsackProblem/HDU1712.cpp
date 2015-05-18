/*************************************************************************
     File Name: HDU1712.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月18日 星期一 16时27分42秒
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
const int N=110;
int a[N][N],dp[N];

int main(){
  int n,m,i,j,k;
  while(~scanf("%d%d",&n,&m)&&(n||m)){
    for(i=1;i<=n;++i)
      for(j=1;j<=m;++j)
        scanf("%d",&a[i][j]);
    Mem0(dp);
    for(i=1;i<=n;++i)
      for(j=m;j>=0;--j)
        for(k=1;k<=j;++k)
          dp[j]=Max(dp[j],dp[j-k]+a[i][k]);
    printf("%d\n",dp[m]);
  }
}
