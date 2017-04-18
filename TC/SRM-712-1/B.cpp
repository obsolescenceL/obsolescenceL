/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Tue 18 Apr 2017 07:33:45 AM EDT
 ************************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

class MakePalindrome {
  public:
    vector <string> constructMinimal(string card) {
      int num[30], i, j;
      vector <string> v;
      string ans = "";
      memset(num, 0, sizeof num);
      for (i = 0; i < card.size(); ++i) num[card[i] - 'a']++;
      for (i = 0; i < 26; ++i) {
        if (num[i]%2 == 0) {
          for (j = 0; j < num[i]/2; ++j) ans += 'a' + i;
        }
      }
      for (i = 0; i < 26; ++i) {
        if (num[i]&1) {
          for (j = 0; j < num[i]; ++j) ans += 'a' + i;
          break;
        }
      }
      for (i = 25; i >= 0; --i) {
        if (num[i]%2 == 0) {
          for (j = 0; j < num[i]/2; ++j) ans += 'a' + i;
        }
      }
      v.push_back(ans);
      for (i = 0; i < 26; ++i)
        if (num[i]&1) break;
      for (++i; i < 26; ++i) {
        if (num[i]&1) {
          ans = "";
          for (j = 0; j < num[i]; ++j) ans += 'a' + i;
          v.push_back(ans);
        }
      }
      return v;
    }
};

int main() {
  MakePalindrome A;
  vector<string> v = A.constructMinimal("ababa");
  for (int i = 0; i < v.size(); ++i) cout<<v[i]<<endl;
}
