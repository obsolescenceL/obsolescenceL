/*************************************************************************
     File Name: 409.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Fri 13 Jan 2017 01:45:55 PM EST
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
  public:
    int longestPalindrome(string s) {
      if (s == "") return 0;
      sort(s.begin(), s.end());
      int ans = 0, cnt = 1, flag = 0;
      char tmp = s[0];
      for (int i = 1; i < s.size(); ++i) {
        if (tmp == s[i]) cnt++;
        else {
          if (cnt%2 == 1) flag = 1;
          tmp = s[i], ans += cnt - cnt%2, cnt = 1;
        }
      }
      if (cnt%2 == 1) flag = 1;
      ans += cnt - cnt%2;
      return ans + flag;
    }
};

int main() {
  string s;
  while (cin>>s) {
    Solution a;
    cout<<a.longestPalindrome(s)<<endl;
  }
}

