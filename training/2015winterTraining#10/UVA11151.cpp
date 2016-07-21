/*************************************************************************
     File Name: I.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年02月03日 星期三 13时28分05秒
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
char s[N];
int dp[N][N];

int main(){
  int t,i,j;
  while(~scanf("%d",&t)){
    getchar();
    while(t--){
      Mem0(dp);
      gets(s);
      //scanf("%s",s);
      int len=strlen(s);
      for(i=len-1;i+1;--i)
        for(j=i+1;j<len;++j)
          if(s[i]==s[j])dp[i][j]=dp[i+1][j-1];
          else dp[i][j]=Min(dp[i+1][j]+1,dp[i][j-1]+1);
      printf("%d\n",len-dp[0][len-1]);
    }
  }
}
