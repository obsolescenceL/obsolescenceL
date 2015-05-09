/*************************************************************************
     File Name: POJ1949.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月08日 星期五 11时37分27秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<vector>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Mem0(x) memset(x,0,sizeof(x))
#define pb push_back
using namespace std;
const int N=10001;
int t[N],dp[N];
vector<int> v[N];

int dfs(int i){
  int& ans=dp[i];
  if(ans)return ans;
  for(int j=0;j<v[i].size();++j)
    ans=Max(ans,dfs(v[i][j]));
  ans+=t[i];
  return ans;
}

int main(){
  int n,m,i,j,x;
  while(~scanf("%d",&n)){
    Mem0(dp);
    for(i=0;i<=n;++i)v[i].clear();
    for(i=1;i<=n;++i){
      scanf("%d%d",t+i,&m);
      if(!m)v[0].push_back(i);
      while(m--){
        scanf("%d",&x);
        v[x].pb(i);
      }
    }
    printf("%d\n",dfs(0));
  }
}
