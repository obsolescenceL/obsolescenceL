/*************************************************************************
     File Name: UVALive4870.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月21日 星期四 14时48分21秒
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
const int N=1010,M=200010;
struct node{
  int f,d;
}v[N];
int dp[M];

int main(){
  int n,k,l,i,j;
  while(~scanf("%d%d%d",&n,&k,&l)&&(n||k||l)){
    MemX(dp);
    for(i=1;i<=n;++i)
      scanf("%d%d",&v[i].f,&v[i].d);
    dp[0]=0;
    int ans=0;
    for(i=1;i<=n;++i){
      for(j=n*20;j>=0;--j){
        if(dp[j]-k<0)dp[j]=0;
        else dp[j]-=k;
        if(j-v[i].f>=0 && dp[j-v[i].f]+v[i].d <= l)
          dp[j]=Min(dp[j],dp[j-v[i].f]+v[i].d);
        //cout<<"dp["<<j<<"]="<<dp[j]<<endl;
        //ans=Max(ans,dp[j]);
        //cout<<"ans="<<ans<<endl;
      }
    }
    for(i=n*20;i>0;--i)
      if(dp[i]<=l)break;
    printf("%d\n",i);
  }
}
