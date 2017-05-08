/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Thu 04 May 2017 10:03:42 AM EDT
 ************************************************************************/
#include<iostream>
using namespace std;

int main() {
  int n, m, f, q, i;
  cin >> n;
  m = n / 2;
  q = n % 2;
  f = 1;
  for (i = 0; i < m; ++i) {
    if (f) {
      cout << "aa";
      f = f ^ 1;
    } else {
      cout << "bb";
      f = f ^ 1;
    }
  }
  if (q) {
    if (f) cout << 'a';
    else cout << 'b';
  }
  cout << endl;
}
