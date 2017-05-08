/*************************************************************************
     File Name: 798d-random-vision.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Tue 25 Apr 2017 09:32:21 AM EDT
 ************************************************************************/
#include<iostream>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
const int N = 1e5 + 10;
struct Node {
  LL a, b;
  int id;
} node[N];
LL a_sum, b_sum, pa_sum, pb_sum;

int main() {
  int n, i;
  cin >> n;
  int nn = n/2 + 1;
  for (i = 0; i < n; ++i) {
    cin >> node[i].a;
    node[i].id = i + 1;
    a_sum += node[i].a;
  }
  for (i = 0; i < n; ++i) {
    cin >> node[i].b;
    b_sum += node[i].b;
  }
  srand(1);
  while (1) {
    random_shuffle(node, node + n);
    pa_sum = pb_sum = 0;
    for (i = 0; i < nn; ++i) {
      pa_sum += node[i].a;
      pb_sum += node[i].b;
    }
    if (2*pa_sum > a_sum && 2*pb_sum > b_sum) {
      cout << nn << endl;
      for (i = 0; i < nn; ++i) cout << node[i].id << ' ';
      cout << endl;
      return 0;
    }
  }
}
