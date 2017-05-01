/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Sat 29 Apr 2017 10:53:24 AM EDT
 ************************************************************************/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int N = 3*1e5 + 10;
struct node {
  int v, id;
  node(int _v, int _id):v(_v), id(_id){}
};
int p[N], vis[N], way[N];
vector<node> v[N];

int main() {
  int n, k, d, i, x, y;
  ios::sync_with_stdio(0);
  cin >> n >> k >> d;
  queue<int> q;
  for (i = 0; i < k; ++i) {
    cin >> p[i];
    vis[p[i]] = 1;
    q.push(p[i]);
  }
  for (i = 1; i < n; ++i) {
    cin >> x >> y;
    v[x].push_back(node(y, i));
    v[y].push_back(node(x, i));
  }
  int ans = n - 1;
  while (!q.empty()) {
    x = q.front();
    q.pop();
    for (i = 0; i < v[x].size(); ++i) {
      if (vis[v[x][i].v]) continue;
      vis[v[x][i].v] = 1;
      way[v[x][i].id] = 1;
      q.push(v[x][i].v);
      ans--;
    }
  }
  cout << ans << endl;
  for (i = 1; i < n; ++i) {
    if (way[i] == 0) cout << i << ' ';
  }
}
