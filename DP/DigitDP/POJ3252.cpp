/*************************************************************************
     File Name: POJ3252.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日  8/21 22:20:39 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=32;
int digit[N],dp[N][N][N];

int dfs(int cur_pos,int cnt_0,int cnt_1,int zero,int limit) {
  if (cur_pos==-1) return cnt_0>=cnt_1;
  int &ans=dp[cur_pos][cnt_0][cnt_1];
  if (!limit && ~ans) return ans;
  ans=0;
  int end=limit? digit[cur_pos]:1,i;
  for (i=0; i<=end; ++i)
    ans+=dfs(cur_pos-1,cnt_0+((!i) & (!zero)),cnt_1+i,zero & (!i),limit & (i==end));
  return ans;
}

int solve(int x) {
  MEM1(dp);
  int tot=-1;
  while (x) {
    digit[++tot]=x%2;
    x/=2;
  }
  return dfs(tot,0,0,1,1);
}

int main() {
  ios::sync_with_stdio(0);
  int start,finish;
  while (cin>>start>>finish) {
    cout<<solve(finish)-solve(start-1)<<endl;
  }
}
