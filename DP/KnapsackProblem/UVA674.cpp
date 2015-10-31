/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 三 10/28 19:50:31 2015
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
const int N=7500;
int coin[]={0,1,5,10,25,50},dp[N];

int main(){
  int n,i,j,k,x;
  //for(i=0;i<N;++i)dp[0][i]=1;
  //for(i=0;i<=5;++i)dp[i][0]=1;
  dp[0]=1;

  for(i=1;i<=5;++i)
    for(j=coin[i];j<N;++j){
      dp[j]+=dp[j-coin[i]];
        //cout<<"i="<<i<<" coin["<<i<<"]="<<coin[i]<<" dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
    }
  while(~scanf("%d",&n)){
    if(!n){puts("0");continue;}
    printf("%d\n",dp[n]);
  }
}
