/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Fri 28 Apr 2017 09:14:51 AM EDT
 ************************************************************************/
#include<iostream>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int main() {
  int n, i, min_p_odd = INF, max_n_odd = -INF, sum = 0, x;
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> x;
    if (x > 0) {
      sum += x;
      if (x&1) min_p_odd = min(min_p_odd, x);
    } else if (x&1) max_n_odd = max(max_n_odd, x);
  }
  if (sum&1) cout << sum << endl;
  else cout << max(sum - min_p_odd, sum + max_n_odd) << endl;
}
