/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Sat 29 Apr 2017 09:49:06 AM EDT
 ************************************************************************/
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
bool h[N];

int main() {
  ios::sync_with_stdio(0);
  int n, m, k, i, x, y, pos = 1;
  cin >> n >> m >> k;
  for (i = 0; i < m; ++i) {
    cin >> x;
    h[x] = 1;
  }
  bool flag = 1;
  for (i = 0; i < k; ++i) {
    cin >> x >> y;
    //cout << x << ' '<< y << endl;
    if (h[pos]) flag = 0;
    if (flag == 0) continue;
    if (pos == x) pos = y;
    else if (pos == y) pos = x;
    //cout << pos << endl;
  }
  cout << pos << endl;
}
