/*************************************************************************
     File Name: UVA10201.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月19日 星期二 16时34分33秒
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
const int N=210,INF=0x3f3f3f3f;
struct node{
  int p,c;
}v[N];
int dp[N][N];
char s[N];

int main(){
  int t,d,i,j,k,dis;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%*c",&d);
      int n=0;
      while(gets(s)!=NULL && s[0]!='\0'){
        n++;
        sscanf(s,"%d%d",&v[n].p,&v[n].c);
      }
      MemX(dp);
      dp[0][100]=0;
      for(i=1;i<=n;++i){
        dis=v[i].p-v[i-1].p;

        for(j=0;j+dis<=200;++j)
          dp[i][j]=Min(dp[i][j],dp[i-1][j+dis]);

        for(j=0;j<=200;++j)
          for(k=0;k<=j;++k)
            if(j+dis-k <= 200 && dp[i-1][j+dis-k]!=INF)
              dp[i][j]=Min(dp[i][j],dp[i-1][j+dis-k]+v[i].c*k);
      }
      dis=d-v[n].p;
      if(dis>100 || dp[n][100+dis]==INF)
        puts("Impossible");
      else printf("%d\n",dp[n][100+dis]);
      if(t)puts("");
    }
  }
}
