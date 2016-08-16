/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月09日 星期六 12时41分59秒
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
const int N=110;

ll solve(ll x){
  if(x&1)return solve(x/2);
  return x/2;
}

int main(){
  int t,n,i;
  ll x;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&n);
      ll sum=0;
      for(i=1;i<=n;++i){
        scanf("%lld",&x);
        //cout<<"----------------"<<endl;
        sum^=solve(x);
      }
      if(!sum)puts("NO");
      else puts("YES");
    }
  }
}
