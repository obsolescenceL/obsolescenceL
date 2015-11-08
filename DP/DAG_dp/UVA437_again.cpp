/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日 11/ 8 13:49:35 2015
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
const int N=100;
struct block{
  int x,y,h;
  block(int _x,int _y,int _h):x(_x),y(_y),h(_h){}
};

int dp[N],n;
bool g[N][N];
vector<block> v;

bool check(int l,int r){
  return v[l].x<v[r].x && v[l].y<v[r].y;
}

int dfs(int i){
  int& ans=dp[i];
  if(ans)return ans;
  ans=v[i].h;
  for(int j=0;j<n;++j)
    if(g[i][j])
      ans=Max(ans,dfs(j)+v[i].h);
  return ans;
}

int main(){
  int x,y,z,i,j,ans,nc=0;
  while(~scanf("%d",&n)&&n){
    v.clear();
    Mem0(g),Mem0(dp);
    for(i=0;i<n;++i){
      scanf("%d%d%d",&x,&y,&z);
      v.pb(block(Min(x,y),Max(x,y),z));
      v.pb(block(Min(y,z),Max(y,z),x));
      v.pb(block(Min(z,x),Max(z,x),y));
    }
    n*=3;
    for(i=0;i<n;++i)
      for(j=0;j<i;++j){
        g[i][j]=check(i,j);
        g[j][i]=check(j,i);
      }
    ans=0;
    for(i=0;i<n;++i)
      ans=Max(ans,dfs(i));
    printf("Case %d: maximum height = %d\n",++nc,ans);
  }
}
