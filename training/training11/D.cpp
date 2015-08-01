/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月29日 星期三 13时04分36秒
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
const int N=100010;
ll s[N];

int main(){
  ll n,d,c;
  int i,t,nc;
  while(~scanf("%I64d",&t)){
    for(nc=1;nc<=t;++nc){
      ll ans=0;
      scanf("%I64d%I64d%I64d",&n,&d,&c);
      for(i=1;i<=n;++i)
        scanf("%I64d",s+i);
      sort(s+1,s+1+n);
      ans=n*d;
      for(i=1;i<=n;++i)
        ans=Min(ans,(ll)s[i]*c*i+d*(n-i));
      printf("Case %d: %I64d\n",nc,ans);
    }
  }
}
