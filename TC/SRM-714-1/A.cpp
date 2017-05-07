/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Sun 07 May 2017 06:42:18 AM EDT
 ************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
class RangeEncoding {
  public:
    int minRanges(vector<int> arr) {
      int ans = 1, i;
      for (i = 1; i < arr.size(); ++i) {
        if (arr[i] != arr[i - 1] + 1) ans ++;
      }
      return ans;
    }
};

int main() {
  RangeEncoding A;
  vector<int> v = {2,4,5,6,8,9,10,11,12,15};
  cout << A.minRanges(v);
}
