/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Thu 04 May 2017 10:04:16 AM EDT
 ************************************************************************/
#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
char s[N];

long long Pow(long long x, int k) {
  long long ans = 1;
  for (; k; k >>= 1) {
    if (k&1) ans = ans*x % mod;
    x = x*x % mod;
  }
  return ans % mod;
}

int main() {
  long long ans = 0;
  cin >> s;
  int len = strlen(s), i;
  for (i = 0; i < len; ++i) {
    if (s[i] == 'a') break;
  }
  int cnt = 0;
  for (; i < len; ++i) {
    if (s[i] == 'a') cnt++;
    else if (s[i] == 'b') ans = (ans + Pow(2, cnt) - 1) % mod;
  }
  cout << ans << endl;
}
