/*************************************************************************
     File Name: baidu-a.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Thu 27 Apr 2017 07:31:08 AM EDT
 ************************************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 110, INF = 0x3f3f3f3f;
int x[N];

int main() {
  ios::sync_with_stdio(0);
  int n, min1, min2, min3, i;
  cin >> n;
  min1 = min2 = min3 = INF;
  for (i = 0; i < n; ++i) {
    cin >> x[i];
  }
  sort(x, x + n, greater<int>());
  for (i = 0; i < n; ++i) {
    if (min1 > x[i]) {
      min3 = min2;
      min2 = min1;
      min1 = x[i];
    }
  }
  if (min3 != INF) cout << min3 << endl;
  else cout << "-1\n";
}
