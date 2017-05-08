/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Sat 22 Apr 2017 01:56:43 AM EDT
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int N = 110;
int a[N];

int main() {
  int n, t, i;
  while (~scanf("%d", &t)) {
    while (t--) {
      scanf("%d", &n);
      int min_a = 2, cnt_1 = 0;
      for (i = 0; i < n; ++i) {
        scanf("%d", a+i);
        if (a[i] == 1) cnt_1++;
        min_a = min(min_a, a[i]);
      }
      if (n < 10 || n > 13 || cnt_1 < 2 || min_a != 1) {
        puts("No");
        continue;
      }
      sort(a, a + n);
      bool flag = 1;
      for (i = 0; i < n - 2; ++i) {
        if (a[i+1] - a[i] > 2) {
          flag = 0;
          break;
        }
      }
      if (flag) puts("Yes");
      else puts("No");
    }
  }
}
