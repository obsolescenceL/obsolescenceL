/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Fri 21 Apr 2017 10:37:31 AM EDT
 ************************************************************************/
#include<iostream>
#include<cstring>
using namespace std;

int main() {
  char s[30];
  cin >> s;
  int len = strlen(s);
  int ans = 0;
  for (int i = 0; i < len/2; ++i) {
    if (s[i] != s[len - 1 -i])
        ans++;
  }
  if (ans == 1 || (ans == 0 && len&1)) cout << "YES" << endl;
  else cout << "NO" << endl;
}

