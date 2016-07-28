/*************************************************************************
     File Name: I.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月28日 星期四 12时52分27秒
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
const int N=110;
int cnt[N];

int main() {
  int n,m,x,i;
  while (~scanf("%d%d",&n,&m)) {
    Mem0(cnt);
    int ans=0;
    for (i=0; i<n; ++i) {
      scanf("%d",&x);
      cnt[x]++;
    }
    for (i=1; i<=n; ++i)
      if (cnt[i]>n/m) ans+=cnt[i]-n/m;
    printf("%d\n",ans);
  }
}
