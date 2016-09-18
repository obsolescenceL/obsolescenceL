/*************************************************************************
     File Name: 1006.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  9/17 13:19:15 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=100000+10;
int de[N],v[N],nn,pre[N];

int find(int x) {
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

void Union(int x,int y) {
  int fx=find(x),fy=find(y);
  if (fx!=fy) {
    pre[fx]=fy;
    nn--;
  }
}

int main() {
  int t,n,m,i,x,y;
  while (~scanf("%d",&t)) {
    while (t--) {
      scanf("%d%d",&n,&m);
      nn=n;
      for (i=1; i<=n; ++i) {
        scanf("%d",v+i);
        pre[i]=i;
      }
      MEM0(de);
      while (m--) {
        scanf("%d%d",&x,&y);
        de[x]++;
        de[y]++;
        Union(x,y);
      }
      int ans=0,cnt=0,cnt1=0,sum=0;
      for (i=1; i<=n; ++i) {
        if (!de[i]) nn--;
        if (de[i]%2) cnt++,de[i]++;
        de[i]/=2;
        if (de[i]%2) ans^=v[i];
      }
      int maxn=0;
      if ((!cnt || cnt==2) && nn<=1) {
        if (!cnt) {
          for (i=1; i<=n; ++i)
            if (de[i]) {
              ans^=v[i];
              maxn=MAX(maxn,ans);
              ans^=v[i];
            }
          ans=maxn;
        }
        printf("%d\n",ans);
      } else puts("Impossible");
    }
  }
}
