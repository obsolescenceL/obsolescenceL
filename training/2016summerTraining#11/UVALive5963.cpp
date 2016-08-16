/*************************************************************************
     File Name: B.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月04日 星期四 11时53分38秒
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
const int N=1000010;
int cnt[N];

int main() {
  int t,nc,i,x,n;
  while (~scanf("%d",&t)) {
    for (nc=1; nc<=t; ++nc) {
      Mem0(cnt);
      scanf("%d",&n);
      bool flag=1;
      for (i=1; i<=n; ++i) {
        scanf("%d",&x);
        if (x>=n) flag=0;
        cnt[x+1]++,cnt[n-x]++;
      }
      for (i=1; i<=n; ++i)
        if (cnt[i]!=2) flag=0;
      printf("Case %d: ",nc);
      if (flag) puts("yes");
      else puts("no");
    }
  }
}
