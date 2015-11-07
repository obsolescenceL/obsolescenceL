/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五 11/ 6 21:39:38 2015
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
const int N=1010,M=110;
int p[N],w[N],mw[M],dp[35];;

int main(){
  int t,n,g,i,j,k;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&n);
      for(i=1;i<=n;++i)
        scanf("%d%d",p+i,w+i);
      scanf("%d",&g);
      for(i=1;i<=g;++i)
        scanf("%d",mw+i);
      int ans=0;
      for(k=1;k<=g;++k){
        Mem0(dp);
        for(i=1;i<=n;++i)
          for(j=mw[k];j>=w[i];--j)
            dp[j]=Max(dp[j],dp[j-w[i]]+p[i]);
        ans+=dp[mw[k]];
      }
      printf("%d\n",ans);
    }
  }
}
