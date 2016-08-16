/*************************************************************************
     File Name: HDU3652.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 二  8/16 11:23:53 2016
 ************************************************************************/
//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=15,mod=13;
int digit[N],dp[N][3][N];

int dfs(int cur_pos,int state,int remainder,int limit) {
  if (cur_pos==-1) return state==2 && remainder%mod==0;
  int &ans=dp[cur_pos][state][remainder];
  if (!limit && ~ans) return ans;
  ans=0;
  int end=limit?digit[cur_pos]:9,i,new_state;
  for (i=0; i<=end; ++i) {
    if (state==2 || (state==1 && i==3)) new_state=2;
    else if (i==1) new_state=1;
    else new_state=0;
    ans+=dfs(cur_pos-1,new_state,(remainder*10+i)%mod,limit & (i==end));
  }
  return ans;
}

int main() {
  int n,tot;
  while (~scanf("%d",&n)) {
    MEM1(dp);
    tot=-1;
    while (n) {
      digit[++tot]=n%10;
      n/=10;
    }
    printf("%d\n",dfs(tot,0,0,1));
  }
}
