/*************************************************************************
     File Name: 455.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Sun 08 Jan 2017 09:03:03 AM EST
 ************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
  public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
      sort(g.begin(), g.end());
      sort(s.begin(), s.end());
      s.push_back(INF*2);
      int ans = 0;
      vector<int>::iterator it = s.begin() - 1;
      for (int i = 0; i < g.size(); ++i) {
        it = lower_bound(it + 1, s.end(), g[i]);
        //cout<<"it="<<*it<<endl;
        //cout<<"g[i]="<<g[i]<<endl;
        if (it == s.end() - 1) break;
        ans++;
      }
      return ans;
    }
};

int main() {
  int n, m, i, x;
  while (cin>>n>>m) {
    vector<int> g, s;
    for (i = 0; i < n; ++i) {
      cin>>x;
      g.push_back(x);
    }
    for (i = 0; i < m; ++i) {
      cin>>x;
      s.push_back(x);
    }
    Solution a;
    cout<<a.findContentChildren(g, s)<<endl;
  }
}
