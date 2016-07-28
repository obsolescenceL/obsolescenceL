/*************************************************************************
     File Name: I.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月27日 星期三 20时18分07秒
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
const int N=1000010,INF=0x3f3f3f3f;
int a[N];

int main() {
  int t,n,m,i,j;
  while (~scanf("%d",&t)) {
    for (int nc=1; nc<=t; ++nc) {
      scanf("%d%d",&n,&m);
      for (i=0; i<m; ++i)
        scanf("%d",a+i);
      sort(a,a+m);
      int maxn=0,minn=INF;
      for (i=j=0; i<m; ++i,j+=n/m) {
        maxn=Max(maxn,a[i]-j);
        minn=Min(minn,a[i]-j);
      }
      printf("Case #%d: %d\n",nc,(maxn-minn+1)/2);
    }
  }
}
