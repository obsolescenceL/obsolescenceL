/*************************************************************************
     File Name: HDU2089.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月13日 星期六 11时25分21秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define LL long long
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=10;
int digit[N],dp[N][3];

int dfs(int cur_pos,int state,int limit) {
  if (cur_pos==-1) return 1;
  int &ans=dp[cur_pos][state];
  if (!limit && ~ans) return ans;
  ans=0;
  int end=limit?digit[cur_pos]:9,i,new_s;
  for (i=0; i<=end; ++i) {
    if (i==4 || (state==1 && i==2)) continue;
    ans+=dfs(cur_pos-1,i==6,limit&(i==end));
  }
  return ans;
}

int solve(int n) {
  MEM1(dp);
  int tot = -1;
  while (n) {
    digit[++tot]=n%10;
    n/=10;
  }
  return dfs(tot,0,1);
}

int main() {
  int n,m;
  while (~scanf("%d%d",&n,&m) && (n||m)) {
    printf("%d\n",solve(m)-solve(n-1));
  }
}
