/*************************************************************************
     File Name: 3.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 三  3/23 20:22:50 2016
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>
#include<bitset>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=1010;
int dp[N][N];

int main(){
  int n,i,j;
  memset(dp,0x3f,sizeof dp);
  scanf("%d",&n);
  for(i=1;i<=n;++i)
    scanf("%d",&dp[i][i]);
  for(i=1;i<=n;++i)
    for(j=i+1;j<=n;++j){
      dp[i][j]=Min(dp[i][j-1],dp[j][j]);
      //cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
    }
  int maxn=0;
  for(i=1;i<=n;++i)
    for(j=i;j<=n;++j){
      dp[i][j]*=j-i+1;
      maxn=Max(maxn,dp[i][j]);
    }
  printf("%d\n",maxn);
  return 0;
}
