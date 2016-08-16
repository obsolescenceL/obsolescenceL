/*************************************************************************
     File Name: D.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月23日 星期六 09时42分10秒
 ************************************************************************/
#include<bits/stdc++.h>
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
const int N=3010;
int a[N],b[N],c[N],dp[N][2];

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i)scanf("%d",b+i);
    for(i=1;i<=n;++i)scanf("%d",c+i);
    dp[1][0]=a[1],dp[1][1]=b[1];
    for(i=2;i<=n;++i){
      dp[i][0]=Max(dp[i-1][0]+b[i],dp[i-1][1]+a[i]);
      dp[i][1]=Max(dp[i-1][0]+c[i],dp[i-1][1]+b[i]);
    }
    printf("%d\n",dp[n][0]);
  }
}
