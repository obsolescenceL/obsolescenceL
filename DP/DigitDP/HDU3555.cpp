/*************************************************************************
     File Name: HDU3555.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月13日 星期六 11时00分54秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define LL long long
#define u64 unsigned long long
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=110;
u64 dp[N][5];
int digit[N];

u64 dfs(int cur_pos,int state,int limit) {
  if (cur_pos==-1) return state==2;
  u64 &ans=dp[cur_pos][state];
  if (!limit && ~ans) return ans;
  ans=0;
  int end=limit? digit[cur_pos]:9,i,new_s;
  for (i=0; i<=end; ++i) {
    if (state==2) new_s=2;
    else if (i==4) new_s=1;
    else if (state==1 && i==9) new_s=2;
    else new_s=0;
    ans+=dfs(cur_pos-1,new_s,limit&(i==end));
  }
  return ans;
}

int main() {
  int t;
  u64 n;
  ios::sync_with_stdio(0);
  while (cin>>t) {
    while (t--) {
      MEM1(dp);
      cin>>n;
      int top=0;
      while (n) {
        digit[top++]=n%10;
        n/=10;
      }
      top--;
      cout<<dfs(top,0,1)<<endl;
    }
  }
}
