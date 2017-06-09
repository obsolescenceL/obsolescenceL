/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Wed 07 Jun 2017 08:01:13 AM EDT
 ************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int flag[N], p[N];
struct Node {
  int a, b;
} node[N];

int main() {
  int n, i, j;
  ios::sync_with_stdio(0);
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> node[i].a;
  }
  for (i = 0; i < n; ++i) {
    cin >> node[i].b;
  }
  int cnt = 0, pos1 = -1, pos2 = -1;
  for (i = 0; i < n; ++i) {
    if (node[i].a == node[i].b) {
      p[i] = node[i].a;
      flag[p[i]] = 1;
      cnt++;
    } else {
      if (pos1 == -1) pos1 = i;
      else pos2 = i;
    }
  }
  if (cnt == n) {
    for (i = 0; i < n - 2; ++i) cout << node[i].a << ' ';
    cout << node[n-1].a << ' ' << node[n-2].a << endl;
    return 0;
  } else if (cnt == n - 1) {
    for (i = 1; i <= n; ++i) if (!flag[i]) p[pos1] = i;
    for (i = 0; i < n; ++i) cout << p[i] << ' ';
    cout << endl;
    return 0;
  } else {
    int f = 1;
    if (flag[node[pos1].a] == 0) {
      p[pos1] = node[pos1].a;
      flag[p[pos1]] = 1;
      if (flag[node[pos2].a] == 0) {
        p[pos2] = node[pos2].a;
        flag[p[pos2]] = 1;
      } else if (flag[node[pos2].b] == 0) {
        p[pos2] = node[pos2].b;
        flag[p[pos2]] = 1;
      } else {
        f = 0;
        flag[p[pos1]] = 0;
      }
    }
    if (!f || flag[node[pos1].b] == 0) {
      p[pos1] = node[pos1].b;
      flag[p[pos1]] = 1;
      if (flag[node[pos2].a] == 0) {
        p[pos2] = node[pos2].a;
        flag[p[pos2]] = 1;
      } else if (flag[node[pos2].b] == 0) {
        p[pos2] = node[pos2].b;
        flag[p[pos2]] = 1;
      }
    }
    for (i = 0; i < n; ++i) cout << p[i] << ' ';
    cout << endl;
    return 0;
  }
}
