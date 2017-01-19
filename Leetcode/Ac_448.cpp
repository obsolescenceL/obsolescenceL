/*************************************************************************
     File Name: 448.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Thu 05 Jan 2017 01:21:41 AM EST
 ************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      vector<int> v;
      int i, n = nums.size();
      for (i = 0; i < n; ++i) {
        v.push_back(i + 1);
      }
      for (i = 0; i < n; ++i) {
        v[nums[i] - 1] = 0;
      }
      nums.clear();
      for (i = 0; i < n; ++i) {
        if (v[i] != 0) nums.push_back(v[i]);
      }
      v.clear();
      for (i = 0; i < nums.size(); ++i) {
        v.push_back(nums[i]);
      }
      return v;
    }
};

int main() {
  int n, x;
  vector<int> nums;
  cin>>n;
  for (int i = 0; i < n; ++i) {
    cin>>x;
    nums.push_back(x);
  }
  Solution a;
  nums = a.findDisappearedNumbers(nums);
  for (int i = 0; i < nums.size(); ++i) {
    cout<<nums[i]<<' ';
  }
}
