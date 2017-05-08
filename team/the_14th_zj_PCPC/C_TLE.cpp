/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Sat 22 Apr 2017 02:14:10 AM EDT
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<string>
#include<cstring>
using namespace std;
const int N = 210, M = 25;
int flag_sum[N];
string s[N], str;
map<string, int> my_s[M], ans;
//set<string> my_s[M], ans;

int main() {
  int t, n, i, j, k, q, c, m;
  ios::sync_with_stdio(0);
  while (cin >> t) {
    while (t--) {
      cin >> n >> q;
      cin >> c;
      for (i = 0; i < c; ++i) {
        cin >> s[i];
      }
      for (i = 0; i < q; ++i) {
        my_s[i].clear();
        cin >> m;
        for (j = 0; j < m; ++j) {
          cin >> str;
          my_s[i][str] = 1;
        }
      }
      int flag;
      memset(flag_sum, 0, sizeof flag_sum);
      for (i = 0; i < n; ++i) {
        ans.clear();
        for (j = 0; j < q; ++j) {
          cin >> flag;
          if (flag) flag_sum[i]++;
          //else flag_sum[i]--;
          for (k = 0; k < c; ++k) {
            if (flag) {
              ans[s[k]] += my_s[j][s[k]];
            } else {
              ans[s[k]] -= my_s[j][s[k]];
            }
          }
        }
        map<string, int>::iterator it;
        int cnt = 0;
        for (it = ans.begin(); it != ans.end(); ++it) {
          if (it->second == flag_sum[i]) cnt++, str = it->first;
          //cout << it->first << ' ' << it->second << endl;
        }
        if (cnt != 1) cout << "Let's go to the library!!" << endl;
        else {
          cout << str << endl;
        }
      }
    }
  }
}
