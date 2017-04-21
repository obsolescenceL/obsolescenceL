/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Fri 21 Apr 2017 10:50:54 AM EDT
 ************************************************************************/
#include<iostream>
#include<cstring>
#include<cmath>
#define LL long long
using namespace std;
const int N = 55, INF = 0x3f3f3f3f;
char s[N][N];
int cnt[N], cnt_tmp[N];
LL seed = 31, key_s[N];

LL BKDR_Hash(char *str, int len) {
  LL hash = 0;
  while (len--) hash = hash*seed + (*str++);
  return (hash & 0x7fffffff);
}

int main() {
  int n, i, j, k, len;
  cin >> n;
  for (i = 0; i < n; ++i) cin >> s[i];
  len = strlen(s[0]);
  for (i = 0; i < len; ++i) cnt[s[0][i] - 'a']++;
  for (i = 1; i < n; ++i) {
    memset(cnt_tmp, 0, sizeof cnt_tmp);
    for (j = 0; j < len; ++j) {
      cnt_tmp[s[i][j] - 'a']++;
    }
    for (j = 0; j < 26; ++j) {
      if (cnt[j] != cnt_tmp[j]) {
        cout << "-1" << endl;
        return 0;
      }
    }
  }
  int min_step = INF, step = 0;
  LL tmp = 1, key_tmp;
  for (i = 0; i < len; ++i) tmp *= seed;
  for (i = 0; i < n; ++i) {
    key_s[i] = BKDR_Hash(s[i], len);
  }
  int flag = 1;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      if (key_s[i] == key_s[j]) continue;
      key_tmp = key_s[j];
      for (k = 0; k < len; ++k) {
        key_tmp = (key_tmp*seed + s[j][k] - s[j][k]*tmp) & 0x7fffffff;
        if (key_tmp == key_s[i]) {
          step += k + 1;
          break;
        }
      }
      if (k == len) {
        flag = 0;
        break;
      }
    }
    min_step = min(min_step, step);
    step = 0;
  }
  if (flag) cout << min_step << endl;
  else cout << "-1" << endl;
}
