/*************************************************************************
     File Name: 2.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Sat 10 Jun 2017 01:26:28 AM EDT
 ************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 255;
int ans[N][N];

int main() {
  int n, m, i, xa, ya, xb, yb, x, y, g, q;
  cin >> n >> m;
  for (i = 1; i <= n; ++i) {
    cin >> xa >> ya >> xb >> yb;
    g = __gcd(ya - yb, xa - xb);
    x = (xa - xb)/g, y = (ya - yb)/g;
    ans[xa][ya] = ans[xb][yb] = i;
    int tmp1 = xb - (xa - x), tmp2 = xb - (xa + x);
    if (tmp1 < 0) tmp1 = -tmp1;
    if (tmp2 < 0) tmp2 = -tmp2;
    if (tmp1 < tmp2) x = -x, y = -y;
    tmp1 = yb - (ya - y), tmp2 = yb - (ya + y);
    if (tmp1 < 0) tmp1 = -tmp1;
    if (tmp2 < 0) tmp2 = -tmp2;
    if (tmp1 < tmp2) x = -x, y = -y;
    xa += x;
    ya += y;
    //cout << "x = " << x << " y = " << y << endl;
    while (xa <= m && xa >= 0 && ya <= m && ya >= 0 && xa != xb) {
      //cout << "xa = " << xa << " ya = " << ya << endl;
      //cout << "xb = " << xb << " yb = " << yb << endl;
      ans[xa][ya] = i;
      xa += x;
      ya += y;
    }
  }
  cin >> q;
  while (q--) {
    cin >> x >> y;
    cout << ans[x][y] << endl;
  }
}
