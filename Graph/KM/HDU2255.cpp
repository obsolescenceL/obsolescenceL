/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 三  8/31 20:39:14 2016
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
#include<algorithm>
#include<iostream>
using namespace std;
const int N=310,INF=0x3f3f3f3f;
typedef long long LL;
LL g[N][N],l1[N],l2[N];
int s[N],t[N],match1[N],match2[N],n;

LL KM() {
  int p,q,i,j,k;
  LL ret = 0;
  for (i = 0; i < n; ++i) {
    l1[i] = -INF;
    for (j = 0; j < n; ++j)
      l1[i] = g[i][j] > l1[i]? g[i][j]:l1[i];
    if (l1[i] == -INF) return -1;
  }
  MEM0(l2),MEM1(match1),MEM1(match2);
  for (i = 0; i < n; ++i) {
    MEM1(t),p = q = 0;
    for (s[0] = i; p <= q && match1[i] < 0; ++p)
      for (k = s[p],j = 0; j < n && match1[i] < 0; ++j) {
        if (l1[k]+l2[j] != g[k][j] || t[j] >= 0) continue;
        s[++q] = match2[j];
        t[j] = k;
        if (s[q] >= 0) continue;
        for (p = j; p>=0; j = p) {
          match2[j] = k = t[j];
          p = match1[k];
          match1[k] = j;
        }
      }
    if (match1[i] >= 0) continue;
    --i,p = INF;
    for (k = 0; k <= q; ++k)
      for (j = 0; j < n; ++j)
        if (t[j] < 0 && l1[s[k]]+l2[j]-g[s[k]][j] < p) p = l1[s[k]]+l2[j]-g[s[k]][j];
    for (j = 0; j < n; ++j) l2[j] += t[j] < 0? 0:p;
    for (k = 0; k <= q; ++k) l1[s[k]] -= p;
  }
  for (i = 0; i < n; ++i)
    ret += g[i][match1[i]];
  return ret;
}

int main() {
  int i,j,v;
  ios::sync_with_stdio(0);
  while (cin>>n) {
    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j) {
        cin>>v;
        g[i][j] = v;
      }
    cout<<KM()<<endl;
  }
}
