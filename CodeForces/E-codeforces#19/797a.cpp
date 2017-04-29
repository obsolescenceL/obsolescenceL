/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Fri 28 Apr 2017 08:58:59 AM EDT
 ************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  int n, k, x = 2;
  vector<int> v;
  cin >> n >> k;
  if (k == 1) {
    cout << n << endl;
    return 0;
  }
  while (n > 1) {
    while (n%x == 0) {
      v.push_back(x);
      n /= x;
      if (v.size() == k - 1) break;
    }
    x++;
    if (v.size() == k - 1) {
      if (n > 1) v.push_back(n);
      break;
    }
  }
  if (v.size() == k) {
    for (int i = 0; i < v.size(); ++i) cout << v[i] << ' ';
  } else cout << "-1";
  cout << endl;
}
