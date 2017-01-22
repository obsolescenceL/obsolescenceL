/*************************************************************************
     File Name: 104.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Fri 06 Jan 2017 06:20:09 AM EST
 ************************************************************************/
#include<iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    void count(TreeNode *p) {
      p->val = 1;
      if (p->left) {
        count(p->left);
        p->val = max(p->val, p->left->val + 1);
      }
      if (p->right) {
        count(p->right);
        p->val = max(p->val, p->right->val + 1);
      }
    }

    int maxDepth(TreeNode *root) {
      if (root == NULL) return 0;
      count(root);
      return root->val;
    }
};
