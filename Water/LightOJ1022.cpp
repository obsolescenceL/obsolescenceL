/*************************************************************************
     File Name: g.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月15日 星期日 18时11分59秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const double pi=2*acos(0.0);

int main(){
  int t,i;
  double r;
  while(~scanf("%d",&t)){
    for(i=1;i<=t;++i){
      scanf("%lf",&r);
      printf("Case %d: %.2f\n",i,r*r*4-r*r*pi);
    }
  }
}
