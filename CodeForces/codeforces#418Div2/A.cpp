/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Wed 07 Jun 2017 08:01:40 AM EDT
 ************************************************************************/
#include<iostream>
using namespace std;
const int N = 1010;
int a[N], b[N], flag[N];

int main() {
  int n, i, k;
  ios::sync_with_stdio(0);
  cin >> n >> k;
  int cnt = 0, f = 1;
  for (i = 0; i < n; ++i) {
    cin >> a[i];
    flag[a[i]]++;
    if (a[i] == 0) cnt++;
    else if (flag[a[i]] > 1) f = 0;
  }
  int kk = k;
  for (i = 0; i < k; ++i) {
    cin >> b[i];
    flag[b[i]]++;
    if (flag[b[i]] > 1) kk--;
  }
  if (cnt == 1) {
    int pos = 0;
    if (a[0] == 0) a[0] = a[1] - 1;
    for (i = 0; i < n - 1; ++i) {
      if (a[i+1] == 0) {
        pos = i + 1;
        a[i+1] = a[i] + 1;
      }
      if (a[i] >= a[i+1]) break;
    }
    //cout << i << endl;
    if (i == n-1) f = 0;
    for (i = 0; i < k; ++i) {
      if (pos == 0) {
        if (b[i] > a[pos+1]) f = 1;
      } else if (pos == n-1) {
        if (b[i] < a[pos-1]) f = 1;
      } else {
        if (b[i] > a[pos+1] || b[i] < a[pos-1]) f = 1;
      }
      //cout << f << endl;
    }
  }
  if (kk < cnt || f == 0) cout << "No" << endl;
  else cout << "Yes" << endl;
}
