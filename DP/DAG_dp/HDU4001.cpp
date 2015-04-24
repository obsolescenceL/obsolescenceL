/*************************************************************************
     File Name: HDU4001.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月24日 星期五 11时15分20秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<vector>
#define Max(x,y) ((x)>(y)?(x):(y))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define pb push_back
using namespace std;
const int N=1001;
struct block{
  ll x,y,h,d;
  block(ll _x,ll _y,ll _h,ll _d):x(_x),y(_y),h(_h),d(_d){}
  bool operator < (const block& rhs) const {
    return x*y<rhs.x*rhs.y || (x*y==rhs.x*rhs.y && d>rhs.d);
  }
};
int n;
ll dp[N];
bool g[N][N];
vector<block> v;

bool check(block lhs,block rhs){
  if(!rhs.d)return lhs.x<=rhs.x && lhs.y<=rhs.y;
  if(rhs.d==1)return (lhs.x<=rhs.x && lhs.y<rhs.y) || (lhs.x<rhs.x && lhs.y<=rhs.y);
  return lhs.x<rhs.x && lhs.y<rhs.y;
}

ll dfs(int i){
  if(dp[i])return dp[i];
  dp[i]=v[i].h;
  for(int j=0;j<n;++j)
    if(g[i][j])dp[i]=Max(dp[i],dfs(j)+v[i].h);
  return dp[i];
}

int main(){
  int i,j,a,b,c,d;
  while(~scanf("%d",&n)&&n){
    v.clear();
    Mem0(dp),Mem0(g);
    for(i=0;i<n;++i){
      scanf("%d%d%d%d",&a,&b,&c,&d);
      if(a<b)swap(a,b);
      v.pb(block(a,b,c,d));
    }
    ll max_h=0;
    for(i=0;i<n;++i)
      for(j=0;j<i;++j){
        if(check(v[i],v[j]))g[i][j]=1;
        if(check(v[j],v[i]))g[j][i]=1;
      }
    for(i=0;i<n;++i)
      max_h=Max(max_h,dfs(i));
    printf("%I64d\n",max_h);
  }
}
