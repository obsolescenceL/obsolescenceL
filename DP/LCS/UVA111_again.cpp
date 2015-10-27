/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 二 10/27 19:19:58 2015
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
const int N=30;
int a[N],b[N],dp[N][N];

int main(){
  int n,i,j,x;
  scanf("%d",&n);
  for(i=1;i<=n;++i)scanf("%d",&x),a[x]=i;
  //for(i=1;i<=n;++i)cout<<a[i]<<' ';
  //cout<<endl;
  while(~scanf("%d",&x)){
    b[x]=1;
    for(i=2;i<=n;++i)
      scanf("%d",&x),b[x]=i;
    //for(i=1;i<=n;++i)cout<<b[i]<<' ';
    //cout<<endl;
    Mem0(dp);
    for(i=1;i<=n;++i)
      for(j=1;j<=n;++j)
        if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=Max(dp[i][j-1],dp[i-1][j]);
    printf("%d\n",dp[n][n]);
  }
}
