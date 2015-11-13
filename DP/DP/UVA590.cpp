/*************************************************************************
     File Name: L.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 二 11/10 18:37:01 2015
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
const int N=15,M=1005,INF=0x3f3f3f3f;
int v[N][N][35],d[N][N],dp[N][M];

int main(){
  int n,k,i,j,l,nc=0;
  while(~scanf("%d%d",&n,&k)&&(n||k)){
    for(i=1;i<=n;++i)
      for(j=1;j<=n;++j){
        if(i==j)continue;
        scanf("%d",&d[i][j]);
        for(l=1;l<=d[i][j];++l){
          scanf("%d",&v[i][j][l]);
          if(!v[i][j][l])
            v[i][j][l]=INF;
        }
      }
    MemX(dp);
    dp[1][0]=0;
    for(l=1;l<=k;++l)
      for(i=1;i<=n;++i)
        for(j=1;j<=n;++j){
          if(i==j)continue;
          int dd=l%d[j][i];
          if(!dd)dd=d[j][i];
          //cout<<"dd="<<dd<<endl;
          dp[i][l]=Min(dp[i][l],dp[j][l-1]+v[j][i][dd]);
          //cout<<"dp["<<i<<"]["<<l<<"]="<<dp[i][l]<<endl;
        }
    printf("Scenario #%d\n",++nc);
    if(dp[n][k]==INF)
      puts("No flight possible.");
    else printf("The best flight costs %d.\n",dp[n][k]);
    puts("");
  }
}
