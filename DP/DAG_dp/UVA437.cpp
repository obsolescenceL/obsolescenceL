/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月23日 星期四 22时10分18秒
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
using namespace std;
const int N=30*3;
struct Block{
  int x,y,h;
  Block(int _x,int _y,int _h):x(_x),y(_y),h(_h){}
  bool operator < (const Block& rhs) const {
    return x*y<rhs.x*rhs.y;
  }
};
int dp[N],n;
bool g[N][N];
vector<Block> v;

bool check(int lhs,int rhs){
  return (v[lhs].x<v[rhs].x && v[lhs].y<v[rhs].y) || (v[lhs].x<v[rhs].y && v[lhs].y<v[rhs].x);
}

int dfs(int i){
  if(dp[i])return dp[i];
  dp[i]=v[i].h;
  for(int j=0;j<n;++j)
    if(g[i][j])
      dp[i]=Max(dp[i],dfs(j)+v[i].h);
  return dp[i];
}

int main(){
  int i,j,nc=0,x,y,z,max_h;
  while(~scanf("%d",&n)&&n){
    max_h=0;
    v.clear();
    Mem0(g),Mem0(dp);
    for(i=0;i<n;++i){
      scanf("%d%d%d",&x,&y,&z);
      v.push_back(Block(x,y,z));
      v.push_back(Block(x,z,y));
      //v.push_back(Block(y,x,z));
      v.push_back(Block(y,z,x));
      //v.push_back(Block(z,x,y));
      //v.push_back(Block(z,y,x));
    }
    //sort(v.begin(),v.end());
    n*=3;
    for(i=0;i<n;++i)
      //dp[i]=v[i].h;
      for(j=0;j<i;++j){
        g[i][j]=check(i,j);
        g[j][i]=check(j,i);
      }
    for(i=0;i<n;++i)
      max_h=Max(max_h,dfs(i));
    printf("Case %d: maximum height = %d\n",++nc,max_h);
  }
}
