/*************************************************************************
     File Name: 461.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Wed 04 Jan 2017 10:13:21 AM EST
 ************************************************************************/
#include<iostream>
#include<cstdio>
using namespace std;

class Solution {
  public:
    int hammingDistance(int x, int y) {
      return __builtin_popcount(x^y);
    }
};

int main() {
  int x, y;
  scanf("%d%d", &x, &y);
  Solution a;
  printf("%d\n", a.hammingDistance(x, y));
}
