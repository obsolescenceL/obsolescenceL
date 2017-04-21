/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Tue 18 Apr 2017 07:11:11 AM EDT
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class RepeatNumberCompare {
  public:
    string compare(int x1, int k1, int x2, int k2) {
      int i;
      string v1 = "", v2 = "";
      string tmp = "";
      while (x1) {
        tmp += x1%10 + '0';
        x1 /= 10;
      }
      reverse(tmp.begin(), tmp.end());
      for (i = 0; i < k1; ++i) v1 += tmp;
      tmp = "";
      while (x2) {
        tmp += x2%10 + '0';
        x2 /= 10;
      }
      reverse(tmp.begin(), tmp.end());
      string ans = "";
      for (i = 0; i < k2; ++i) v2 += tmp;
      //cout << v1 << endl << v2 <<endl;
      if (v1.size() > v2.size()) ans = "Greater";
      else if (v1.size() < v2.size()) ans = "Less";
      else {
        for (i = 0; i < v1.size(); ++i) {
          if (v1[i] > v2[i]) {
            ans = "Greater";
            break;
          } else if (v1[i] < v2[i]) {
            ans = "Less";
            break;
          }
        }
        if (i == v1.size()) ans = "Equal";
      }
      return ans;
    }
};

int main() {
  RepeatNumberCompare A;
  cout << A.compare(5, 9, 555555556, 1);
}
