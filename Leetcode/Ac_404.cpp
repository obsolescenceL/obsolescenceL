/*************************************************************************
     File Name: 404.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Sun 08 Jan 2017 11:04:51 AM EST
 ************************************************************************/

#include<iostream>
struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  int ans;
  public:
    void solve(TreeNode *p, int f) {
      int check = 0;
      if (p->left) check++, solve(p->left, 1);
      if (p->right) check++, solve(p->right, 0);
      if (f && !check) ans += p->val;
    }
    int sumOfLeftLeaves(TreeNode *root) {
      ans = 0;
      if (root) solve(root, 0);
      return ans;
    }
};

int main() {
}
