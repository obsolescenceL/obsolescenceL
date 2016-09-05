/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  9/ 5 23:26:53 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define pb push_back
#define MEM(a,x) memset(a,x,sizeof(a))
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=410;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int g[N][N],l1[N],l2[N],s[N],t[N],match1[N],match2[N],n,ans[N];

void KM() {
  int p,q,i,j,k;
  for (i=0; i < n; ++i) {
    l1[i]=-INF;
    for (j=0; j < n; ++j)
      l1[i]=g[i][j]>l1[i]? g[i][j]:l1[i];
  }
  MEM(l2,0),MEM(match1,-1),MEM(match2,-1);
  for (i=0; i < n; ++i) {
    MEM(t,-1),p=q=0;
    for (s[0]=i; p <= q && match1[i] < 0; ++p)
      for (k=s[p],j=0; j < n && match1[i] < 0; ++j) {
        if (l1[k]+l2[j]!=g[k][j] || t[j] >= 0) continue;
        s[++q]=match2[j];
        t[j]=k;
        if (s[q] >= 0) continue;
        for (p=j; p >= 0; j=p) {
          match2[j]=k=t[j];
          p=match1[k];
          match1[k]=j;
        }
      }
    if (match1[i] >= 0) continue;
    --i,p=INF;
    for (k=0; k <= q; ++k)
      for (j=0; j < n; ++j)
        if (t[j] < 0 && l1[s[k]]+l2[j]-g[s[k]][j] < p)
          p=l1[s[k]]+l2[j]-g[s[k]][j];
    for (j=0; j < n; ++j)
      l2[j]+=t[j]<0? 0:p;
    for (k=0; k <= q; ++k)
      l1[s[k]]-=p;
  }
  MEM(ans,-1);
  
  for (i=0; i < n; ++i) {
    if (g[i][match1[i]])
      printf("%d%c",match1[i]+1," \n"[i==n-1]);
    else printf("0%c"," \n"[i==n-1]);

  }
}

int v[N];

int main() {
  int k,i,j,x;
  while (~scanf("%d",&n)) {
    MEM(g,0);
    for (i=0; i < n; ++i)
      scanf("%d",v+i);
    for (i=0; i < n; ++i) {
      scanf("%d",&k);
      for (j=0; j < k; ++j) {
        scanf("%d",&x);
        x--;
        g[i][x]=v[i];
      }
    }
    KM();
  }
}
