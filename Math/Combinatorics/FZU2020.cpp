/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五  4/ 1 23:05:57 2016
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
const int N=10010;

ll Pow(ll x,ll k,ll mod){
  ll ans=1;
  for(;k;k>>=1){
    if(k&1)ans=ans*x%mod;
    x=x*x%mod;
  }
  return ans;
}

int main(){
  int t,i,n,m,p;
  ios::sync_with_stdio(0);
  while(cin>>t){
    while(t--){
      cin>>n>>m>>p;
      ll ans=1,fac=1;
      for(i=0;i<m;++i){
        ans=ans*(n-i)%p;
        fac=fac*(i+1)%p;
      }
      ans=ans*Pow(fac,p-2,p)%p;
      cout<<ans<<endl;
    }
  }
}
