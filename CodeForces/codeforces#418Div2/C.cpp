/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Wed 07 Jun 2017 08:00:53 AM EDT
 ************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
const int N = 1510;
char s[N];
int cnt[30], ans[30][1500];
vector<int> start[30];

int main() {
  ios::sync_with_stdio(0);
  int n, i, ch, k, l, q, m;
  char op[5];
  cin >> n >> s;
  for (i = 0; i < n; ++i) {
    cnt[s[i] - 'a']++;
    if (i && s[i] == s[i-1]) continue;
    start[s[i] - 'a'].push_back(i);
  }
  for (ch = 0; ch < 26; ++ch) {
    //cout << "j = " << j  << endl;
    for (i = 1; i <= n; ++i) {
      if (cnt[ch] == 0) {
        ans[ch][i] = i;
        continue;
      }
      if (i >= n - cnt[ch]) {
        ans[ch][i] = n;
        continue;
      }
      for (k = 0; k < start[ch].size(); ++k) {
        int tmp = 0, ii = i;
        //if (ch == 12 && i == 4) cout << k << endl;
        for (l = start[ch][k]; l < n; ++l) {
          if (s[l] - 'a' != ch) {
            if (ii == 0) break;
            ii--;
          }
          tmp++;
        }
        ans[ch][i] = max(ans[ch][i], tmp + ii);
      }
    }
  }
  cin >> q;
  while (q--) {
    cin >> m >> op;
    //cout << "ans[" << op[0]-'a' << "][" << m << "] = " ;
    cout << ans[op[0]-'a'][m] << endl;
  }
}
