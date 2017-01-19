/*************************************************************************
     File Name: 350.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Thu 19 Jan 2017 09:06:12 AM EST
 ************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
      vector<int> v;
      if (nums1.size() == 0 || nums2.size() == 0) return v;
      sort(nums1.begin(), nums1.end());
      sort(nums2.begin(), nums2.end());
      for (int i = 0, j = 0; i < nums1.size(); ++i) {
        while (j < nums2.size() && nums2[j] < nums1[i]) ++j;
        if (j == nums2.size()) break;
        if (nums1[i] == nums2[j]) {
          ++j;
          v.push_back(nums1[i]);
        }
      }
      return v;
    }
};

int main() {
  vector<int> nums1, nums2;
  int n, m, x;
  cin>>n>>m;
  for (int i = 0; i < n; ++i) {
    cin>>x;
    nums1.push_back(x);
  }
  for (int i = 0; i < m; ++i) {
    cin>>x;
    nums2.push_back(x);
  }
  Solution a;
  vector<int> v = a.intersect(nums1, nums2);
  for (int i = 0; i < v.size(); ++i) {
    cout<<v[i]<<endl;
  }
}
