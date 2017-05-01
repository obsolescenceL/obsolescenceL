/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Sat 29 Apr 2017 11:00:37 AM EDT
 ************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
const int N = 3*1e5 + 10, INF = 0x3f3f3f3f;
vector<int> v[N];
int a[N];
bool is_max[N], is_second_max[N];

int main() {
  ios::sync_with_stdio(0);
  int n, i, maxn = -INF;
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin >> a[i];
    //cout << a[i]<<endl;
    maxn = max(maxn, a[i]);
    //cout << maxn << endl;
  }
  int cnt_maxn = 0, cnt_second_max = 0;
  for (i = 1; i <= n; ++i) {
    if (maxn == a[i]) {
      is_max[i] = 1;
      cnt_maxn++;
    }
    if (maxn == a[i] + 1) {
      is_second_max[i] = 1;
      cnt_second_max++;
    }
  }
  int x, y;
  for (i = 0; i < n - 1; ++i) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int ans = INF, j, tmp_cnt_max, tmp_cnt_second_max;
  for (i = 1; i <= n; ++i) {
    tmp_cnt_max = is_max[i];
    tmp_cnt_second_max = 0;
    for (j = 0; j < v[i].size(); ++j) {
      if (is_second_max[v[i][j]]) tmp_cnt_second_max++;
      if (is_max[v[i][j]]) tmp_cnt_max++;
    }
    if (a[i] == maxn && cnt_maxn == 1) {
      //cout <<" ----"<<endl;
      if (cnt_second_max == tmp_cnt_second_max) ans = min(ans, maxn);
      else ans = min(ans, maxn + 1);
    } else if (cnt_maxn == tmp_cnt_max) ans = min(ans, maxn + 1);
    else if (cnt_maxn != tmp_cnt_max) ans = min(ans, maxn + 2);
  }
  cout << ans << endl;
}
