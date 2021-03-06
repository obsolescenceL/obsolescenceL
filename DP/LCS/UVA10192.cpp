/*************************************************************************
     File Name: UVA10192.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六 10/31 22:18:31 2015
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
char s[N],ss[N],dp[N][N];

int main(){
  int i,j,nc=0;
  while(gets(s)&&s[0]!='#'){
    gets(ss);
    int len1=strlen(s),len2=strlen(ss);
    for(i=1;i<=len1;++i)
      for(j=1;j<=len2;++j)
        if(s[i-1]==ss[j-1])dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=Max(dp[i-1][j],dp[i][j-1]);
    printf("Case #%d: you can visit at most %d cities.\n",++nc,dp[len1][len2]);
  }
}
