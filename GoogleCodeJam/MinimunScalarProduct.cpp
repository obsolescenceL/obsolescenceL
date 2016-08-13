/*************************************************************************
     File Name: MinimunScalarProduct.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月24日 星期二 16时34分49秒
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
using namespace std;
long long a1[810],a2[810];


int main(){
  int t,k,n,i;
  //ios::sync_with_stdio(0);
  while(~scanf("%d",&t)){
    for(k=1;k<=t;++k){
      scanf("%d",&n);
      for(i=0;i<n;++i)scanf("%lld",a1+i);
      for(i=0;i<n;++i)scanf("%lld",a2+i);
      sort(a1,a1+n);
      sort(a2,a2+n,greater<long long>());
      long long ans=0;
      for(i=0;i<n;++i){
        ans+=a1[i]*a2[i];
        //ans+=a1[n-1-i]*a2[n-1-i];
      }
      //if(n%2)ans+=a1[n/2]*a2[n/2];
      //cout<<"Case #"<<k<<": "<<ans<<'\n';
      printf("Case #%d: %lld\n",k,ans);
    }
  }
}
