/*************************************************************************
     File Name: HDU2199.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月05日 星期日 17时24分49秒
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
#define Abs(x,y) ((x)-(y)>0?((x)-(y)):((y)-(x)))
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
using namespace std;
const double eps=1e-5;

double Pow(double x,int k){
  double ans=1;
  for(;k;k>>=1){
    if(k&1)ans*=x;
    x*=x;
  }
  return ans;
}

double function(double mid){
  return 8*Pow(mid,4)+7*Pow(mid,3)+2*mid*mid+3*mid+6;
}

int main(){
  int t;
  double y;
  int max_y=8*Pow(100,4)+7*Pow(100,3)+2*10000+300+6,min_y=6;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%lf",&y);
      if(y<min_y||y>max_y){
        puts("No solution!");
        continue;
      }
      double low=0,high=100,mid,mid_f;
      while(high-low>-eps){
        mid=(high+low)/2;
        mid_f=function(mid);
        if(Abs(mid_f,y)<=eps)break;
        if(mid_f<=y)low=mid;
        else high=mid;
      }
      printf("%.4f\n",mid);
    }
  }
}
