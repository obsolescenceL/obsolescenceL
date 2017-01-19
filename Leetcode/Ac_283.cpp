/*************************************************************************
     File Name: 283.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Sun 08 Jan 2017 10:06:32 AM EST
 ************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    void moveZeros(vector<int> &nums) {
      int i, j = 0;
      for (i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) continue;
        swap(nums[i], nums[j++]);
      }
    }
};

int main() {
  int n, i, x;
  while (cin>>n) {
    vector<int> nums;
    for (i = 0; i < n; ++i) {
      cin>>x;
      nums.push_back(x);
    }
    Solution a;
    a.moveZeros(nums);
    for (i = 0; i < n; ++i) {
      cout<<nums[i]<<endl;
    }
  }
}
