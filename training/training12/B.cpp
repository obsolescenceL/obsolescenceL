/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月01日 星期六 12时55分44秒
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
ll tim[N];

int main(){
  int n,q,i;
  while(~scanf("%d%d",&n,&q)){
    for(i=1;i<=n;++i){
      scanf("%I64d",tim+i);
      tim[i]+=tim[i-1];
    }
    ll t;
    while(q--){
      scanf("%I64d",&t);
      t%=tim[n];
      int pos=lower_bound(tim+1,tim+1+n,t)-tim;
      if(tim[pos]==t)pos++;
      printf("%d\n",pos);
    }
  }
}
