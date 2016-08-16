/*************************************************************************
     File Name: 1012.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年09月19日 星期六 12时09分09秒
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
const int N=5e6+10;
ll v[N];

int main(){
  int t,n,i;
  ll a,b;
  while(~scanf("%d",&t)){
    for(int nc=1;nc<=t;++nc){

      scanf("%d%I64d%I64d",&n,&a,&b);
      //cout<<"n="<<n<<" a="<<a<<" b="<<b<<endl;
      int flag=1;
      for(i=1;i<=n;++i)
        scanf("%I64d",&v[i]);

      sort(v+1,v+1+n);

      ll maxn=(ll)(a*v[n]*v[n]+b*v[n-1]);
      for(i=1;i<=n;++i){
        if(i==n) maxn=Max(maxn,(ll)(a*v[i]*v[i]+b*v[n-1]));
        else maxn=Max(maxn,(ll)(a*v[i]*v[i]+b*v[n]));
        if(i==1) maxn=Max(maxn,(ll)(a*v[i]*v[i]+b*v[2]));
        else maxn=Max(maxn,(ll)(a*v[i]*v[i]+b*v[1]));
      }

      printf("Case #%d: %I64d\n",nc,maxn);
    }
  }
}
