/*************************************************************************
     File Name: 349.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Sun 08 Jan 2017 11:23:41 AM EST
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
   public:
     vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
       vector<int>::iterator it1, it2;
       sort(nums1.begin(), nums1.end());
       sort(nums2.begin(), nums2.end());
       it1 = unique(nums1.begin(), nums1.end());
       it2 = unique(nums2.begin(), nums2.end());
       vector<int> v;
       for (vector<int>::iterator i = nums1.begin(), j = nums2.begin(); i != it1; ++i) {
         //cout<<"nums1["<<i<<"]="<<nums1[i]<<endl;
         while (j != it2 && *i > *j) ++j;
         if (j == it2) break;
         if (*i == *j) v.push_back(*i), ++j;
       }
       return v;
     }
};

int main() {
  int n, m, i, x;
  while (cin>>n>>m) {
    vector<int> nums1, nums2;
    for (i = 0; i < n; ++i) {
      cin>>x;
      nums1.push_back(x);
    }
    for (i = 0; i < m; ++i) {
      cin>>x;
      nums2.push_back(x);
    }
    Solution a;
    vector<int> v = a.intersection(nums1, nums2);
    for (i = 0; i < v.size(); ++i) {
      cout<<v[i]<<endl;
    }
  }
}
