/*************************************************************************
     File Name: D.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月01日 星期一 12时38分06秒
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
const int N=20;
int a[N],dp[1<<N];

int main() {
  int n,i,j,k,l;
  while (~scanf("%d",&n)) {
    for (i=0; i<n; ++i)
      scanf("%d",a+i);
    sort(a,a+n);
    Mem0(dp);
    int ans=0,tmp;
    for (i=0; i<n; ++i)
      for (j=i+1; j<n; ++j)
        for (k=j+1; k<n; ++k) {
          if (a[i]+a[j]<=a[k]) continue;
          for (l=0; l<(1<<n); ++l) {
            if ((l>>i)&1) continue;
            if ((l>>j)&1) continue;
            if ((l>>k)&1) continue;
            tmp=l|(1<<i)|(1<<j)|(1<<k);
            dp[tmp]=Max(dp[tmp],dp[l]+1);
            ans=Max(ans,dp[tmp]);
          }
        }
    printf("%d\n",ans);
  }
}
