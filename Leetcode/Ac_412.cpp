/*************************************************************************
     File Name: 412.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Wed 04 Jan 2017 10:28:37 AM EST
 ************************************************************************/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
  public:
    string toString(int i) {
      string s = "";
      while (i > 0) {
        s += '0' + (i%10);
        i /= 10;
      }
      reverse(s.begin(), s.end());
      return s;
    }

    vector<string> fizzBuzz(int n) {
      vector<string> v;
        for (int i = 1; i <= n; ++i) {
          string s = "";
          if (i%3 == 0) s += "Fizz";
          if (i%5 == 0) s += "Buzz";
          if (i%3 && i%5) s += toString(i);
          s += '\0';
          v.push_back(s);
        }
        return v;
    }
};

int main() {
  int n;
  while (~scanf("%d", &n)) {
    Solution a;
    vector<string> v = a.fizzBuzz(n);
    for (int i = 0; i < n; ++i)
      cout<<v[i]<<endl;
  }
}
