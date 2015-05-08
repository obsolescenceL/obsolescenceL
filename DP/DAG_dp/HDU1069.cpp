/*************************************************************************
     File Name: HDU1069.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月08日 星期五 11时36分56秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<vector>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Mem0(x) memset(x,0,sizeof(x))
#define pb push_back
using namespace std;
const int N=30*3+10;
struct Block{
  int x,y,h;
  Block(int _x,int _y,int _h):x(_x),y(_y),h(_h){}
};
int dp[N],n;
bool g[N][N];
vector<Block> v;

bool check(int lhs,int rhs){
  return (v[lhs].x<v[rhs].x && v[lhs].y<v[rhs].y) || (v[lhs].x<v[rhs].y && v[lhs].y<v[rhs].x);
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

int main(){//与UVA437一样的题
  int i,j,nc=0,x,y,z,max_h;
  while(~scanf("%d",&n)&&n){
    max_h=0;
    v.clear();
    Mem0(g),Mem0(dp);
    for(i=0;i<n;++i){
      scanf("%d%d%d",&x,&y,&z);
      v.pb(Block(x,y,z));
      v.pb(Block(x,z,y));
      v.pb(Block(y,z,x));
    }
    n*=3;
    for(i=0;i<n;++i)
      for(j=0;j<i;++j){
        g[i][j]=check(i,j);
        g[j][i]=check(j,i);
      }
    for(i=0;i<n;++i)
      max_h=Max(max_h,dfs(i));
    printf("Case %d: maximum height = %d\n",++nc,max_h);
  }
}
