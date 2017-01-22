/*************************************************************************
     File Name: 168.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Mon 09 Jan 2017 01:23:06 AM EST
 ************************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
  public:
    string convertToTitle(int n) {
      string s = "";
      while (n > 0) {
        if (n % 26 == 0) s += 'Z', n -= 26;
        else s += 'A' + (n%26) - 1;
        n /= 26;
      }
      reverse(s.begin(), s.end());
      return s;
    }
};

int main() {
  int n;
  while (cin>>n) {
    Solution a;
    string s = a.convertToTitle(n);
    cout<<s<<endl;
  }
}
