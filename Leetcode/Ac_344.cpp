/*************************************************************************
     File Name: 344.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Wed 04 Jan 2017 11:09:42 AM EST
 ************************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
  public:
    string reverseString(string s) {
      reverse(s.begin(), s.end());      //void reverse();
      return s;
    }
};

int main() {
  string s;
  cin>>s;
  Solution a;
  cout<<a.reverseString(s)<<endl;
}
