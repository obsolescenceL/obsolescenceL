/*************************************************************************
     File Name: HDU3709.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五  8/19 17:36:19 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=20;
int digit[N];
LL dp[N][N*N*N];

LL dfs(int cur_pos,int state,int pivot,int limit) {
  if (cur_pos == -1) return !state;
  if (state < 0) return 0;
  LL &ans = dp[cur_pos][state];
  if (!limit && ~ans) return ans;
  ans = 0;
  int end = limit? digit[cur_pos]:9,i;
  for (i = 0; i <= end; ++i)
    ans += dfs(cur_pos-1,state+i*(cur_pos-pivot),pivot,limit&(i == end));
  return ans;
}

LL solve(LL x) {
  if (x < 0) return 0;
  int tot=-1;
  while (x) {
    digit[++tot]=x%10;
    x/=10;
  }
  LL ans=0;
  for (int i=0; i<=tot; ++i) {
    MEM1(dp);
    ans += dfs(tot,0,i,1);
  }
  return ans-tot;
}

int main() {
  int t;
  LL x,y;
  while (cin>>t) {
    while (t--) {
      cin>>x>>y;
      cout<<solve(y)-solve(x-1)<<endl;
    }
  }
}
