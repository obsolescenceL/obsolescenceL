/*************************************************************************
     File Name: POJ1651.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月10日 星期五 21时06分06秒
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
const int N=110,INF=0x3f3f3f3f;
using namespace std;
ll dp[N][N],a[N];

int main(){
  int n,i,j,k;
  while(~scanf("%d",&n)){
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i){
      for(j=1;j<=n;++j)
        dp[i][j]=INF;
      dp[i][i]=0;
    }
    for(i=n-2;i;--i)
      for(j=i+1;j<n;++j)
        for(k=i;k<j;++k){
          dp[i][j]=Min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
        }
    printf("%d\n",dp[1][n-1]);
  }
}
