/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月29日 星期三 15时04分00秒
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

int main(){
  int t,nc;
  ll n,m;
  while(~scanf("%d",&t)){
    for(nc=1;nc<=t;++nc){
      scanf("%I64d%I64d",&n,&m);
      ll l=1,r=n,mid;
      while(l<r){
        mid=(l+r)>>1;
        if(((mid*(mid+1))>>1)>=m)r=mid;
        else l=mid+1;
      }
      printf("Case %d: %I64d %I64d\n",nc,r-1,r-1-((r*(r+1)>>1)-m));
    }
  }
}
