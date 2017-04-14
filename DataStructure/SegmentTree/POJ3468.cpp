/*************************************************************************
     File Name: POJ3468.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月16日 星期四 15时07分08秒
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
#define LL long long
using namespace std;
const int N = 1e5 + 10;
struct Tree {
  LL sum;
  int add;
} tree[N<<2];
LL ans;

void pushUp(int t) {
  tree[t].sum = tree[t<<1].sum + tree[t<<1|1].sum;
}

void pushDown(int t, int L, int R) {
  if (tree[t].add == 0) return;
  int mid = (L + R) >> 1;
  tree[t<<1].sum += (LL)tree[t].add*(mid - L + 1);
  tree[t<<1|1].sum += (LL)tree[t].add*(R - mid);
  tree[t<<1].add += tree[t].add;
  tree[t<<1|1].add += tree[t].add;
  tree[t].add = 0;
}

void build(int t, int L, int R) {
  tree[t].add = 0;
  if (L == R) {
    scanf("%I64d", &tree[t].sum);
    return;
  }
  int mid = (L + R) >> 1;
  build(t<<1, L, mid);
  build(t<<1|1, mid+1, R);
  pushUp(t);
}

void update(int t, int L, int R, int l, int r, int c) {
  if (l <= L && R <= r) {
    tree[t].sum += (LL)c*(R - L + 1);
    tree[t].add += c;
    return;
  }
  int mid = (L + R) >> 1;
  pushDown(t, L, R);
  if (l <= mid) update(t<<1, L, mid, l, r, c);
  if (r > mid) update(t<<1|1, mid+1, R, l, r, c);
  pushUp(t);
}

void query(int t, int L, int R, int l, int r) {
  if (l <= L && R <= r) {
    ans += tree[t].sum;
    return;
  }
  int mid = (L + R) >> 1;
  pushDown(t, L, R);
  if (l <= mid) query(t<<1, L, mid, l, r);
  if (r > mid) query(t<<1|1, mid+1, R, l, r);
}


int main() {
  int n, q, l, r, c;
  char op[10];
  while (~scanf("%d%d", &n, &q)) {
    build(1, 1, n);
    while (q--) {
      scanf("%s%d%d", op, &l, &r);
      if (op[0] == 'C') {
        scanf("%d", &c);
        update(1, 1, n, l, r, c);
      } else if (op[0] == 'Q') {
        ans = 0;
        query(1, 1, n, l, r);
        printf("%I64d\n", ans);
      }
    }
  }
}
