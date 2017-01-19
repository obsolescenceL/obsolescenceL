/*************************************************************************
     File Name: 476.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Fri 13 Jan 2017 01:20:31 PM EST
 ************************************************************************/
#include<iostream>
using namespace std;

class Solution {
  public:
    int findComplement(int num) {
      int temp = 1, ans = 0;
      while (num > 0) {
        if (num%2 == 0) ans += temp;
        temp *= 2;
        num /= 2;
      }
      return ans;
    }
};

int main() {
  int num;
  while (cin>>num) {
    Solution a;
    cout<<a.findComplement(num)<<endl;
  }
}
