/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Mon 01 May 2017 08:40:10 AM EDT
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cmath>
#define LL long long
using namespace std;
const int N = 1e5 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3f;
LL a[N];

int main() {
  ios::sync_with_stdio(0);
  int n, i;
  LL minn = INF, k;
  cin >> n >> k;
  for (i = 0; i < n; ++i) {
    cin >> a[i];
    minn = min(a[i], minn);
  }
  LL ans = 0;
  for (i = 0; i < n && ans >= 0; ++i) {
    LL tmp = a[i] - minn;
    if (tmp%k == 0) ans += tmp/k;
    else ans = -1;
  }
  cout << ans << endl;
}
