/*************************************************************************
     File Name: MakeData.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Fri 09 Jun 2017 08:41:05 AM EDT
 ************************************************************************/
#include<iostream>
using namespace std;

int main() {
  freopen("in.txt", "w", stdout);
  srand(time(0));
  int n = 1500;
  cout << n << endl;
  for (int i = 0; i < n; ++i) {
    cout << (char)(rand()%26 + 'a');
  }
  cout << endl;
  cout << n*26 << endl;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 26; ++j) {
      cout << i << ' ' << (char)(j+'a') << endl;
    }
  }
}
