/*************************************************************************
     File Name: Hrbust2235.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月28日 星期六 22时05分15秒
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
double p[1000001];


int main(){
  int t,n,k,m;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d%d",&n,&k,&m);
      //cout<<n<<' '<<k<<' '<<m<<endl;
      p[1]=1;
      for(int i=2;i<=n;++i)p[i]=p[i-1]+((i-1)*k)%m;
      //for(int i=1;i<=n;++i)cout<<"p["<<i<<"]="<<p[i]<<endl;
      /*
      while(n!=1){
        p[1]=2*sqrt(p[1]*p[n]);
        //cout<<p[1]<<endl;
        n--;
        sort(p+1,p+1+n);
      }
      */
      for(int i=n-1;i;--i){
        p[i]=2*sqrt(p[i]*p[i+1]);
      }
      printf("%.3lf\n",p[1]);
    }
  }
}
