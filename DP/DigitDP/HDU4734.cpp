/*************************************************************************
     File Name: HDU4734.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 二  8/23 21:38:00 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=20,M=10000;
int digit[N],dp[N][M];

int dfs(int cur_pos,int state,int limit) {
  if (cur_pos==-1) return 1;
  int &res=dp[cur_pos][state];
  if (!limit && ~res) return res;
  int ans=0;
  int end=limit? digit[cur_pos]:9,i;
  for (i=0; i<=end; ++i) {
    int new_state=state-i*(1<<cur_pos);
    if (new_state < 0) continue;
    ans+=dfs(cur_pos-1,new_state,limit & (i==end));
  }
  return limit? ans:res=ans;
}

int solve(int a,int b) {
  int tmp=0,cnt=1,tot=-1;
  while (a) {
    tmp+=(a%10)*cnt;
    a/=10;
    cnt<<=1;
  }
  while (b) {
    digit[++tot]=b%10;
    b/=10;
  }
  return dfs(tot,tmp,1);
}

int main() {
  int t,a,b;
  MEM1(dp);
  while (~scanf("%d",&t)) {
    for (int nc=1; nc<=t; ++nc) {
      scanf("%d%d",&a,&b);
      printf("Case #%d: %d\n",nc,solve(a,b));
    }
  }
}
