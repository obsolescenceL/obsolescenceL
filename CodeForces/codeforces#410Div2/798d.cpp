/*************************************************************************
     File Name: d.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Mon 24 Apr 2017 10:27:12 AM EDT
 ************************************************************************/
#include<algorithm>
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
struct Node {
  int a, b, id;
  bool operator < (const Node & rhs) const {
    return a > rhs.a;
  }
} node[N];
int id_ans[N];

int main() {
  int n, i, j;
  ios::sync_with_stdio(0);
  cin >> n;
  cout << n/2 + 1 << endl;
  for (i = 0; i < n; ++i) cin >> node[i].a;
  for (i = 0; i < n; ++i) {
    cin >> node[i].b;
    node[i].id = i + 1;
  }
  sort(node, node + n);
  int pos = 0;
  id_ans[pos++] = node[0].id;
  if (n&1) {
    i = 1;
  } else {
    id_ans[pos++] = node[1].id;
    i = 2;
  }
  for (; i < n; i +=2) {
    if (node[i].b > node[i+1].b) id_ans[pos++] = node[i].id;
    else id_ans[pos++] = node[i+1].id;
  }
  for (i = 0; i < pos - 1; ++i) cout << id_ans[i] << ' ';
  cout << id_ans[pos-1] << endl;
}
