/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Fri 21 Apr 2017 11:29:30 AM EDT
 ************************************************************************/
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N];

int main() {
  int n, gcd_a, i;
  cin >> n >> a[0] >> a[1];
  gcd_a = __gcd(a[0], a[1]);
  for (i = 2; i < n; ++i) {
    cin >> a[i];
    gcd_a = __gcd(gcd_a, a[i]);
  }
  //cout << gcd_a << endl;
  if (gcd_a > 1) {
    cout << "YES" << endl << "0" << endl;
    return 0;
  }
  int ans = 0;
  for (i = 0; i < n - 1; ++i) {
    if (a[i]&1) {
      if ((a[i] + a[i+1])%2 == 0 && (a[i] - a[i+1])%2 == 0) {
        int tmp = a[i];
        ans++;
        a[i] = a[i] - a[i+1];
        a[i+1] = tmp + a[i+1];
      } else {
        int tmp = a[i];
        ans += 2;
        a[i] = -2*a[i+1];
        a[i+1] = 2*tmp;
      }
      ++i;
    }
  }
  if (a[n-2]%2 == 0 && (a[n-1]&1)) {
    if ((a[n-2] + a[n-1])%2 == 0 && (a[n-2] - a[n-1])%2 == 0) ans++;
    else ans += 2;
  }
  cout << "YES" << endl;
  cout << ans << endl;
}
