/*************************************************************************
     File Name: 171.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Mon 09 Jan 2017 01:49:14 AM EST
 ************************************************************************/
#include<iostream>
using namespace std;

class Solution {
  public:
    int titleToNumber(string s) {
      if (s == "") return 0;
      int ans = s[0] - 'A' + 1;
      for (int i = 1; i < s.size(); ++i) {
        ans = ans *26 + s[i] - 'A' + 1;
      }
      return ans;
    }
};


int main() {
  string s;
  while (cin>>s) {
    Solution a;
    cout<<a.titleToNumber(s)<<endl;
  }
}
