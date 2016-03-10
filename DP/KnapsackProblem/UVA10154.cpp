/*************************************************************************
     File Name: UVA10154.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月14日 星期四 21时40分30秒
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
const int N=10010,INF=0x3f3f3f3f;
struct node{
  int w,l;
  bool operator < (const node& rhs)const {
    return l<rhs.l || (l==rhs.l && w < rhs.w);
  }
}s[N];
int dp[N];

int main(){
  int n=0,i,j;
  while(~scanf("%d",&s[n].w)){
    scanf("%d",&s[n].l);
    if(s[n].w<=s[n].l)n++;
  }
  if(!n){puts("0");return 0;}
  sort(s,s+n);
  MemX(dp);
  dp[0]=0;
  int ans=1;
  for(i=0;i<n;++i){
    //if(s[i].w>s[i].l)continue;
    for(j=n;j>=1;--j){
      if(s[i].l >= dp[j-1]+s[i].w)
        dp[j]=Min(dp[j],dp[j-1]+s[i].w);
      if(dp[j]<INF)ans=Max(ans,j);
    }
  }
  printf("%d\n",ans);
}
