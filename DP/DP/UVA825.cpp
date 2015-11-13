/*************************************************************************
     File Name: H.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 四 11/12 13:33:12 2015
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
bool g[N][N];
char s[N];

int main(){
  int t,w,n,i,j,k,x;
  while(~scanf("%d",&t)){
    while(t--){
      Mem0(dp),Mem0(g);
      scanf("%d%d%*c",&w,&n);
      for(i=1;i<=w;++i){
        scanf("%d",&x);
        gets(s);
        int cur=0,len=strlen(s);
        for(j=0;j<=len;++j){
          if(isdigit(s[j]))
            cur=cur*10+s[j]-'0';
          else g[x][cur]=1,cur=0;
        }
      }
      dp[1][0]=1;
      for(i=1;i<=w;++i)
        for(j=1;j<=n;++j){
          dp[i][j]=dp[i-1][j]+dp[i][j-1];
          if(g[i][j])dp[i][j]=0;
        }
      printf("%d\n",dp[w][n]);
      if(t)puts("");
    }
  }
}
