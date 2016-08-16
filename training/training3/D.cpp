/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月27日 星期一 13时11分11秒
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
const ll mod=1e9+9;

ll get_sum(ll n,ll m){
  ll i,sum=1;
  for(i=0;i<n;++i)
    sum=(sum*(m-i))%mod;
  for(i=n;i;--i)
    sum/=i;
  return sum%mod;
}

ll Pow(ll x,ll k){
  ll ans=1;
  while(k){
    if(k&1)ans=(ans*x)%mod;
    x*=x;
    k>>=1;
  }
  return ans;
}

int main(){
  ll n,i;
  while(~scanf("%I64d",&n)){
    ll ans=0,temp,mid=(n+1)/2;
    for(i=1;i<mid;++i){
      temp=get_sum(i,n)%mod;
      //cout<<"temp="<<temp<<endl;
      ans=ans+(temp*(Pow(2,n-i)-1))%mod;
      ans=ans+(temp*(Pow(2,i)-1))%mod;
      ans%=mod;
      //cout<<"ans="<<ans<<endl;
    }
    temp=get_sum(mid,n)%mod;
    if(n%2==0)ans=(ans+(temp*(Pow(2,mid)-1))%mod)%mod;
    printf("%I64d\n",ans);
  }
}
