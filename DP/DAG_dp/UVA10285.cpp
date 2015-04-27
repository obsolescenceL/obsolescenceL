/*************************************************************************
     File Name: UVA10285.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月27日 星期一 20时35分18秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<string>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Mem0(x) memset(x,0,sizeof(x))
using namespace std;
const int N=101;
int n,m,mp[N][N],dp[100*N],g[100*N][5];

inline int ID(int x,int y){
  return (x-1)*m+y;
}

inline int dfs(int i){
  if(dp[i])return dp[i];
  int& ans=dp[i]=1;
  for(int j=0;j<4;++j)
    if(g[i][j])ans=Max(ans,dfs(g[i][j])+1);
  return ans;
}

int main(){
  int t,i,j;
  string name;
  ios::sync_with_stdio(0);
  while(cin>>t){
    while(t--){
      Mem0(dp),Mem0(g);
      cin>>name>>n>>m;
      for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
          cin>>mp[i][j];
      int id;
      for(i=1;i<=n;++i)
        for(j=1;j<=m;++j){
          id=ID(i,j);
          if(i-1 && mp[i][j]>mp[i-1][j])
            g[id][0]=id-m;
          if(i<n && mp[i][j]>mp[i+1][j])
            g[id][1]=id+m;
          if(j-1 && mp[i][j]>mp[i][j-1])
            g[id][2]=id-1;
          if(j<m && mp[i][j]>mp[i][j+1])
            g[id][3]=id+1;
        }
      int max_l=0;
      for(i=1;i<=n*m;++i)
        max_l=Max(max_l,dfs(i));
      cout<<name<<": "<<max_l<<'\n';
    }
  }
}
