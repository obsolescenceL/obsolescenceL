/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Fri 28 Apr 2017 09:27:46 AM EDT
 ************************************************************************/
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
const int N = 1e5 + 10;
int pos_s[30];
char s[N];

int main() {
  int i, len, j;
  stack<char> sta;
  cin >> s;
  len = strlen(s);
  for (i = 0; i < len; ++i) {
    pos_s[s[i]-'a'] = i;
  }
  for (i = j = 0; i < 26; ++i) {
    for (; j <= pos_s[i]; ++j) {
      if (s[j] == 'a' + i) cout << s[j];
      else sta.push(s[j]);
    }
    while (!sta.empty() && sta.top() <= 'a' + i + 1) {
      cout << sta.top();
      sta.pop();
    }
  }
  while (!sta.empty()) {
    cout << sta.top();
    sta.pop();
  }
  cout << endl;
}
