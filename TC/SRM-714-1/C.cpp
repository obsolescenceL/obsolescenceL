/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Sun 07 May 2017 07:40:10 AM EDT
 ************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
class Salewoman {
  public:
    int minMoves(vector<int> pos, vector<int> delta) {
      int first_n = 0, cur_n = 0, cur_p = 0, ans = 0, cur_pos = 0;
      for (int i = 0; i < pos.size(); ++i) {
        if (first_n == 0 && delta[i] < 0) {
          first_n = pos[i];
        }
        if (delta[i] < 0) {
          cur_n += -delta[i];
        } else {
          cur_p += delta[i];
        }
        if (cur_p >= cur_n && cur_n) {
          ans += 2*(pos[i] - first_n);
          //cout << "pos["<<i << "]=" << pos[i] << endl;
          //cout << ans << endl;
          first_n = 0;
          cur_p -= cur_n;
          cur_n = 0;
          cur_pos = pos[i];
        }
      }
      return ans + pos[pos.size() - 1];
    }
};

int main() {
  Salewoman A;
  vector<int> v1 = {1,2,4,8,16,32,64,128};
  vector<int> v2 = {-1,-1,-1,-1,1,1,1,1};
  cout << A.minMoves(v1, v2);
}
