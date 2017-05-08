/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Wed 26 Apr 2017 10:07:30 PM EDT
 ************************************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
  char s[10], t[10];
  cin >> s >> t;
  int sx = s[0] - 'a', sy = s[1] - '0';
  int tx = t[0] - 'a', ty = t[1] - '0';
  int x = sx - tx, y = sy - ty, i, tmp;
  if (x >= 0 && y >= 0) {
    tmp = min(x, y);
    x -= tmp;
    y -= tmp;
    cout << tmp + x + y << endl;
    for (i = 0; i < tmp; ++i) cout << "LD\n";
    while (x--) cout << "L\n";
    while (y--) cout << "D\n";
  } else if (x < 0 && y < 0) {
    x = -x, y = -y;
    tmp = min(x, y);
    x -= tmp;
    y -= tmp;
    cout << tmp + x + y << endl;
    for (i = 0; i < tmp; ++i) cout << "RU\n";
    while (x--) cout << "R\n";
    while (y--) cout << "U\n";
  } else if (x < 0) {
    x = -x;
    tmp = min(x, y);
    x -= tmp;
    y -= tmp;
    cout << tmp + x + y << endl;
    for (i = 0; i < tmp; ++i) cout << "RD\n";
    while (x--) cout << "R\n";
    while (y--) cout << "D\n";
  } else {
    y = -y;
    tmp = min(x, y);
    x -= tmp;
    y -= tmp;
    cout << tmp + x + y << endl;
    for (i = 0; i < tmp; ++i) cout << "LU\n";
    while (x--) cout << "L\n";
    while (y--) cout << "U\n";
  }
}
