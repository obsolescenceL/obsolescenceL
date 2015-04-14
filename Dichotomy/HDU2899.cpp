/*************************************************************************
     File Name: HDU2899.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月06日 星期一 12时19分47秒
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
using namespace std;
const double eps=1e-5;
double y;

double Pow(double x,int k){
  double ans=1;
  for(;k;k>>=1){
    if(k&1)ans*=x;
    x*=x;
  }
  return ans;
}

double g(double x){
  return 42*Pow(x,6)+48*Pow(x,5)+21*Pow(x,2)+10*x;
}

double f(double x){
  return 6*Pow(x,7)+8*Pow(x,6)+7*Pow(x,3)+5*x*x-y*x;
}

int main(){
  int t;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%lf",&y);
      double low=0,high=100,mid,mid_g;
      while(high-low>eps){
        //cout<<high<<' '<<low<<endl;
        mid=(high+low)/2;
        mid_g=g(mid);
        if(mid_g<y)low=mid;
        else high=mid;
      }
      //cout<<"mid="<<mid<<endl;
      //cout<<f(mid)<<endl;
      printf("%.4f\n",f(mid));
    }
  }
}
