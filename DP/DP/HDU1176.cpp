/*************************************************************************
     File Name: HDU1176.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: Sun 16 Apr 2017 01:32:56 AM EDT
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int dp[N][15];

int main() {
  int n, i, j, T, x;
  //freopen("in.txt","r",stdin);
  //freopen("out2.txt","w",stdout);
  while (~scanf("%d", &n) && n) {
    memset(dp, 0, sizeof dp);
    int maxT = 0;
    while (n--) {
      scanf("%d%d", &x, &T);
      maxT = max(T, maxT);
      dp[T][x + 1]++;
    }
    for (i = maxT - 1; i >= 0; --i) {
      for (j = 1; j <= 11; ++j) {
        dp[i][j] += max(dp[i + 1][j], max(dp[i + 1][j + 1], dp[i + 1][j - 1]));
      }
    }
    printf("%d\n", dp[0][6]);
  }
}
