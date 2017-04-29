/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Fri 28 Apr 2017 09:59:18 AM EDT
 ************************************************************************/
#include<iostream>
#include<cmath>
using namespace std;
const int N = 1e5 + 10;

int a[N], n;
int dp[N][320];

int dfs(int p, int k) {
  if (p > n) return 0;
  return dp[p][k] = (dp[p][k]? dp[p][k]: dfs(p + a[p] + k, k) + 1);
}

int main() {
  int q, p, k, i;
  cin >> n;
  int nn = sqrt(n) + 1;
  for (i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  cin >> q;
  while (q--) {
    cin >> p >> k;
    int cnt = 1;
    if (k >= nn) {
      while (p + a[p] + k <= n) {
        p = p + a[p] + k;
        cnt++;
      }
      cout << cnt << endl;
    } else {
      cout << dfs(p, k) << endl;
    }
  }
}
