/*************************************************************************
     File Name: 463.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Thu 05 Jan 2017 01:39:04 AM EST
 ************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int islandPerimeter(vector<vector<int>>& grid) {
      int h = grid.size(), w = grid[0].size(), i, j, p = 0;
      for (i = 0; i < h; ++i) {
        for (j = 0; j < w; ++j) {
          if (grid[i][j] == 0) continue;
          if (i == 0 || grid[i - 1][j] == 0) p++;
          if (i+1 == h || grid[i + 1][j] == 0) p++;
          if (j == 0 || grid[i][j - 1] == 0) p++;
          if (j+1 == w || grid[i][j + 1] == 0) p++;
        }
      }
      return p;
    }
};

int main() {
  int h, w, x;
  cin>>h>>w;
  vector<vector<int>> grid;
  vector<int> v;
  for (int i = 0; i < h; ++i) {
    v.clear();
    for (int j = 0; j < w; ++j) {
      cin>>x;
      v.push_back(x);
    }
    grid.push_back(v);
  }
  Solution a;
  cout<<a.islandPerimeter(grid);
}
