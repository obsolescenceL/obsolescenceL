/*************************************************************************
     File Name: J.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日 11/ 1 10:09:02 2015
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
const int N=30010;
int coin[]={0,5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[N];

int main(){
  int i,j;
  double n;
  dp[0]=1;
  for(i=1;i<=11;++i)
    for(j=coin[i];j<=N;++j)
      dp[j]+=dp[j-coin[i]];
  while(~scanf("%lf",&n)&&n){
    int ans=n*100+0.5;
    printf("%6.2f%17lld\n",n,dp[ans]);
  }
}
