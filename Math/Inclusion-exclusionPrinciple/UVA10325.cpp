/*************************************************************************
     File Name: UVA10325.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月29日 星期三 18时33分58秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll a[20];

int main(){
  ll n,m,i,j,ans,temp,cnt;
  while(~scanf("%lld%lld",&n,&m)){
    for(i=0;i<m;++i)scanf("%lld",a+i);
    ans=0;
    for(i=1;i<(1<<m);++i){
      temp=-1,cnt=0;
      for(j=0;j<m;++j)
        if(i&(1<<j)){
          cnt++;
          if(temp==-1)temp=a[j];
          else temp=temp/(__gcd(temp,a[j]))*a[j];
        }
      if(cnt&1)ans+=n/temp;
      else ans-=n/temp;
    }
    printf("%lld\n",n-ans);
  }
}

