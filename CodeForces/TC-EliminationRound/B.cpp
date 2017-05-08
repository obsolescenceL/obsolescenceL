/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Mon 01 May 2017 08:54:03 AM EDT
 ************************************************************************/
#include<queue>
#include<iostream>
using namespace std;
const int N = 1010;
struct node {
  int x, y, change, d;
}s, t, x;
char mp[N][N];
bool vis[N][N][4];
int mx[] = {0, 0, 1, -1}, my[] = {1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(0);
  int n, m, i, j;
  cin >> n >> m;
  for (i = 0; i < n; ++i) {
    cin >> mp[i];
    //cout << mp[i] << endl;
    for (j = 0; j < m; ++j) {
      if (mp[i][j] == 'S') {
        s.x = i, s.y = j, s.change = 0, s.d = -1;
      }
      if (mp[i][j] == 'T') {
        t.x = i, t.y = j;
      }
    }
  }
  queue<node> q;
  //for (i = 0; i < 4; ++i) {
    //s.d = i;
    q.push(s);
  //}
  bool flag = 0;
  while (!q.empty()) {
    s = q.front();
    q.pop();
    //cout << "s("<<s.x<<','<<s.y<<','<<s.d<<','<<s.change<<")\n";
    if (s.x == t.x && s.y == t.y && s.change <= 3) {
      flag = 1;
      break;
    }
    for (i = 0; i < 4; ++i) {
      x.x = s.x + mx[i];
      x.y = s.y + my[i];
      if (s.d != i) x.change = s.change + 1;
      else x.change = s.change;
      x.d = i;
      if (x.x < 0 || x.x >= n) continue;
      if (x.y < 0 || x.y >= m) continue;
      if (mp[x.x][x.y] == '*') continue;
      if (vis[x.x][x.y][s.d]) continue;
      if (x.change > 3) continue;
      vis[x.x][x.y][s.d] = 1;
      //cout << "s("<<s.x<<','<<s.y<<','<<s.d<<','<<s.change<<")\n";
      //cout << "x("<<x.x<<','<<x.y<<','<<x.d<<','<<x.change<<")\n";
      q.push(x);
    }
  }
  if (flag) cout << "YES\n";
  else cout << "NO\n";
}
