/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  9/ 5 09:32:38 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<vector>
#include<cstdio>
using namespace std;
const int N=1010;
const int INF=0x3f3f3f3f;
int a[N],b[N];
vector<pair<int,int> > v;

int main() {
  int n,m,i,x;
  scanf("%d%d",&n,&m);
  while (m--) {
    scanf("%d",&x);
    a[x]++;
    int x2=n;
    for (i=x+1; i<n; ++i)
      if (a[i]==2) {x2=i;break;}
    int x0=-1;
    for (i=x2-1; i>=x; --i)
      if (!a[i]) {x0=i;break;}
    if (x2<n && x>=x0) {
      a[x2]=0;
      a[x2+1]++;
    }
    if (a[x]>=2) a[x]-=2,a[x+1]++;
    int cnt=0;
    for (i=0; i<n; ++i)
      if (a[i]!=b[i]) cnt++,v.pb(make_pair(i,a[i]));
    printf("%d",cnt);
    for (i=0; i<cnt; ++i)
      printf(" %d %d",v[i].first,v[i].second);
    v.clear();
    puts("");
    for (i=0; i<n; ++i) b[i]=a[i];
  }
}
