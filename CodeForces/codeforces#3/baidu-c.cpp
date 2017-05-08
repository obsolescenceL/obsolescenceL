/*************************************************************************
     File Name: baidu-c.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Thu 27 Apr 2017 07:54:57 AM EDT
 ************************************************************************/
#include<iostream>
using namespace std;
const int N = 1010, mod = 2017;

int Pow(int x, int k) {
  int ans = 1;
  for (; k; k >>= 1) {
    if (k&1) ans = (ans*x)%mod;
    x = (x*x)%mod;
  }
  return ans;
}

int main() {
  int n, k, ans_1;
  cin >> n >> k;
  if (k == 0 || k == n - 1) {
    cout << '1' << endl;
    return 0;
  }
  //cout << Pow(2, 4) << endl;
  if (k == 1 || k == n - 2) {
    cout << Pow(2, n) - n - 1<< endl;
  }
}
