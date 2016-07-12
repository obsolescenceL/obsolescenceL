/*************************************************************************
     File Name: hrbcuacm_A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  5/23 22:54:25 2016
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
const int N=110;
int dp[N][5];
char str[N];

int main(){
  int t,i,j;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%s",str);
      int n=strlen(str);
      MemX(dp);
      if(str[0]>='A' && str[0]<='Z')
        dp[0][0]=dp[0][1]=2;
      else dp[0][0]=1;
      for(i=1;i<n;++i){
        if(str[i]>='A' && str[i]<='Z'){
          dp[i][0]=Min(dp[i-1][0]+2,dp[i-1][1]+2);
          dp[i][1]=Min(dp[i-1][0]+2,dp[i-1][1]+1);
        }else{
          dp[i][0]=Min(dp[i-1][0]+1,dp[i-1][1]+2);
          dp[i][1]=Min(dp[i-1][0]+2,dp[i-1][1]+2);
        }
        //cout<<"dp["<<i<<"][0]="<<dp[i][0]<<" dp["<<i<<"][1]="<<dp[i][1]<<endl;
      }
      dp[n-1][1]++;
      printf("%d\n",Min(dp[n-1][0],dp[n-1][1]));
    }
  }
}
