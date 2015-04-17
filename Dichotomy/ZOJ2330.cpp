/*************************************************************************
     File Name: ZOJ2330.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月17日 星期五 22时55分19秒
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
const double eps=1e-7,E=exp(1.0);

int main(){
  double a;
  while(~scanf("%lf",&a)){
    if(a-E>-eps){
      puts("-1");
      continue;
    }
    double low=E,high=50,mid,c=log(a)/a,d;
    while(high-low>-eps){
      mid=(low+high)/2;
      d=log(mid)/mid;
      if(d<c)high=mid-eps;
      else low=mid+eps;
    }
    printf("%.5f\n",low);
  }
}
