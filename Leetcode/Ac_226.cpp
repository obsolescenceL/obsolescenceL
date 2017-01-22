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
    void Invert(TreeNode *p) {
      if (p->left) Invert(p->left);
      if (p->right) Invert(p->right);
      if (p->left && p->right) swap(p->left, p->right);
      else if (p->left) p->right = p->left, p->left = NULL;
      else if (p->right) p->left = p->right, p->right = NULL;
    }

    TreeNode* invertTree(TreeNode *root) {
      if (root) Invert(root);
      return root;
    }
};
