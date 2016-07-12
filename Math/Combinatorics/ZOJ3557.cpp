/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  4/ 2 12:10:12 2016
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

ll Pow(ll x,ll k,ll p){
  ll ans=1;
  for(;k;k>>=1){
    if(k&1)ans=ans*x%p;
    x=x*x%p;
  }
  return ans;
}

ll Comb(ll n,ll m,ll p){
  if(n<m)return 0;
  if(m>n-m)m=n-m;
  ll ans=1;
  for(int i=0;i<m;++i){
    ans=ans*(n-i)%p;
    ans=ans*Pow(i+1,p-2,p)%p;
  }
  return ans;
}

int main(){
  ll n,m,p;
  ios::sync_with_stdio(0);
  while(cin>>n>>m>>p){
    ll ans=1;
    n=n-m+1;
    while(m){
      ans=ans*Comb(n%p,m%p,p)%p;
      n/=p,m/=p;
    }
    cout<<ans<<endl;
  }
}
