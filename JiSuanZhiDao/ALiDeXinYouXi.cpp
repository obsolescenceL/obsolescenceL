/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Sat 20 May 2017 06:56:09 AM EDT
 ************************************************************************/
#include<iostream>
using namespace std;
const int N = 10;
int a[N][N];

int main() {
  int n, m, i, x, y;
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (i = 0; i < n; ++i) {
    cin >> x >> y;
    a[x+3][y+3] = 1;
  }
  for (i = 0; i < m; ++i) cin >> x >> y;
  int ans = 0;
  if (a[6][0] && a[3][0] && a[0][0]) ans++;
  if (a[6][0] && a[6][3] && a[6][6]) ans++;
  if (a[6][6] && a[3][6] && a[0][6]) ans++;
  if (a[0][0] && a[0][3] && a[0][6]) ans++;
  
  if (a[5][1] && a[3][1] && a[1][1]) ans++;
  if (a[1][1] && a[1][3] && a[1][5]) ans++;
  if (a[1][5] && a[3][5] && a[5][5]) ans++;
  if (a[5][5] && a[5][3] && a[5][1]) ans++;

  if (a[4][2] && a[3][2] && a[2][2]) ans++;
  if (a[2][2] && a[2][3] && a[2][4]) ans++;
  if (a[2][4] && a[3][4] && a[4][4]) ans++;
  if (a[4][2] && a[4][3] && a[4][4]) ans++;

  if (a[3][0] && a[3][1] && a[3][2]) ans++;
  if (a[3][4] && a[3][5] && a[3][6]) ans++;
  if (a[6][3] && a[5][3] && a[4][3]) ans++;
  if (a[2][3] && a[1][3] && a[0][3]) ans++;

  cout << ans << endl;
}
