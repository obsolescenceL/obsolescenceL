/*************************************************************************
     File Name: e.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月04日 星期一 14时34分57秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll lucky[20],unlucky,high,n;

inline ll lcm(ll a,ll b){
  ll gcd_n=__gcd(a,b);
  if(a/gcd_n>high/b)return high+1;
  return a/gcd_n*b;
}

inline ll solved(ll m){
  ll ans=0,temp,cnt,i,j;
  for(i=1;i<(1<<n);++i){
    temp=1,cnt=0;
    for(j=0;j<n;++j)
      if(i&(1<<j)){
        cnt++;
        temp=lcm(temp,lucky[j]);
      }
    if(cnt&1)ans+=m/temp-m/lcm(temp,unlucky);
    else ans-=m/temp-m/lcm(temp,unlucky);
  }
  return ans;
}

int main(){
  ll m,i,low,temp;
  while(~scanf("%lld%lld%lld%lld",&n,&m,&low,&high)&&(n||m||low||high)){
    for(i=0;i<n;++i)scanf("%lld",lucky+i);
    scanf("%lld",&unlucky);
    for(i=1;i<m;++i){
      scanf("%lld",&temp);
      unlucky=lcm(unlucky,temp);
    }
    //for(i=0;i<m;++i)scanf("%lld",unlucky+i);
    printf("%lld\n",solved(high)-solved(low-1));
  }
}
