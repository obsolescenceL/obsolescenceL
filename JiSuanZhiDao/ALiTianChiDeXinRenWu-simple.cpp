/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Sat 20 May 2017 06:56:28 AM EDT
 ************************************************************************/
#include<iostream>
#include<cstring>
#define LL long long
using namespace std;
const int N = 1e6 + 10, M = 1e6 + 10;
int w[N];
char t[M], s[N];
LL seed = 131;

LL BKDR_Hash(char *str, int len) {
  LL hash = 0;
  while (len--) hash = hash*seed + (*str++);
  return (hash & 0x7fffffff);
}

int main() {
  int n, a, b, L, R, i, keyt, keys;
  ios::sync_with_stdio(0);
  cin >> n >> a >> b >> L >> R;
  cin >> t;
  int len = strlen(t), ans = 0;
  keyt = BKDR_Hash(t, len);
  w[0] = b;
  for (i = 1; i < n; ++i) {
    w[i] = (w[i-1] + a) % n;
  }
  LL tmp = 1;
  for (i = 0; i < len; ++i) {
    if (L <= w[i] && w[i] <= R) {
      if (w[i] & 1) s[i] = 'T';
      else s[i] = 'A';
    } else {
      if (w[i] & 1) s[i] = 'C';
      else s[i] = 'G';
    }
    tmp = (tmp*seed) & 0x7fffffff;
  }
  keys = BKDR_Hash(s, len);
  if (keyt == keys) ans++;
  for (i = len; i < n; ++i) {
    if (L <= w[i] && w[i] <= R) {
      if (w[i] & 1) s[i] = 'T';
      else s[i] = 'A';
    } else {
      if (w[i] & 1) s[i] = 'C';
      else s[i] = 'G';
    }
    keys = (keys*seed + s[i] - s[i-len]*tmp) & 0x7fffffff;
    if (keyt == keys) ans++;
  }
  cout << ans << endl;
}
