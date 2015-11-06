/*************************************************************************
     File Name: UVA116.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日 11/ 1 22:45:32 2015
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
const int N=110,M=15;
int dp[M][N],ans[M][N];

int main(){
  int n,m,i,j;
  while(~scanf("%d%d",&n,&m)){
    for(i=1;i<=n;++i)
      for(j=1;j<=m;++j)
        scanf("%d",&dp[i][j]);
    MemX(ans);

    for(j=m;j>=2;--j)
      for(i=1;i<=n;++i){
        int a=i-1,b=i+1;
        if(i==1)a=n;
        if(i==n)b=1;
        int min_n=Min(dp[i][j],Min(dp[a][j],dp[b][j]));
        dp[i][j-1]+=min_n;
        if(min_n==dp[a][j])
          ans[i][j-1]=a;
        if(min_n==dp[i][j])
          ans[i][j-1]=Min(ans[i][j-1],i);
        if(min_n==dp[b][j])
          ans[i][j-1]=Min(ans[i][j-1],b);
        //cout<<"dp["<<i<<"]["<<j-1<<"]="<<dp[i][j-1]<<endl;
        //cout<<"ans["<<i<<"]["<<j<<"]="<<ans[i][j]<<endl;
       
      }
    int min_n=dp[1][1],pos=1;
    for(i=2;i<=n;++i)
      if(min_n>dp[i][1]){
        min_n=dp[i][1];
        pos=i;
      }
    if(m==1)printf("%d",pos);
    else printf("%d %d",pos,ans[pos][1]);
    for(j=2,i=ans[pos][1];j<m;i=ans[i][j],++j)
      printf(" %d",ans[i][j]);
    printf("\n%d\n",min_n);
  }
}
