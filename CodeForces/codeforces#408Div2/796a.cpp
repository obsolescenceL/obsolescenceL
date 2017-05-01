/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Sat 29 Apr 2017 09:33:47 AM EDT
 ************************************************************************/
#include<iostream>
using namespace std;
const int N = 110;
int a[N];

int main() {
  int n, m, k, i, ans;
  cin >> n >> m >> k;
  ans = n + 1;
  for (i = 1; i <= n; ++i) cin >> a[i];
  for (i = 1; i < m && i + m <= n; ++i) {
    if (a[m-i] && a[m-i] <= k) {
      ans = min(ans, i);
      break;
    }
    if (a[m+i] && a[m+i] <= k) {
      ans = min(ans, i);
      break;
    }
  }
  int tmp = i;
  for (i = tmp; i < m; ++i) {
    if (a[m-i] && a[m-i] <= k) {
      ans = min(ans, i);
      break;
    }
  }
  for (i = tmp; i + m <= n; ++i) {
    if (a[m+i] && a[m+i] <= k) {
      ans = min(ans, i);
      break;
    }
  }
  cout << ans*10 << endl;
}
