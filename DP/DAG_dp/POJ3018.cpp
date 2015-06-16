/*************************************************************************
     File Name: POJ3018.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月16日 星期二 20时46分49秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Mem0(x) memset(x,0,sizeof(x))
using namespace std;
const int N=1010,M=510;
int dp[M],box[M][N],n,m;
bool g[M][M];

bool check(int lhs,int rhs){
  for(int i=0;i<m;++i)
    if(box[lhs][i]>=box[rhs][i])
      return 0;
  return 1;
}

int dfs(int i){
  int& ans=dp[i];
  if(ans)return ans;
  ans=1;
  for(int j=0;j<=n;++j)
    if(g[i][j])ans=Max(ans,dfs(j)+1);
  return ans;
}

int main(){
  int i,j;
  while(~scanf("%d%d",&n,&m)){
    Mem0(dp),Mem0(g);
    for(i=0;i<=n;++i){
      for(j=0;j<m;++j)
        scanf("%d",box[i]+j);
      sort(box[i],box[i]+m);
    }
    for(i=0;i<=n;++i)
      for(j=1;j<=n;++j)
        if(check(i,j))g[i][j]=1;
    int maxn=1;
    maxn=Max(maxn,dfs(0));
    if(maxn>1)printf("%d\n",maxn-1);
    else puts("Please look for another gift shop!");
  }
}
