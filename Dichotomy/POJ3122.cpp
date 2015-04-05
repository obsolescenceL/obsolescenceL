/*************************************************************************
     File Name: POJ3122.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月05日 星期日 17时15分54秒
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
using namespace std;
const double Pi=acos(-1.0);
const double eps=1e-5;
const int N=10010;
double pie_size[N];

int main(){
  int n,f,t,r,sum,i;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d",&n,&f);
      f++;
      double max_size=0;
      for(i=0;i<n;++i){
        scanf("%d",&r);
        pie_size[i]=Pi*r*r;
        max_size=Max(max_size,pie_size[i]);
      }
      double low=0,high=max_size,mid;
      while(high-low>eps){
        mid=(low+high)/2;
        sum=0;
        for(i=0;i<n;++i)
          sum+=pie_size[i]/mid;
        if(sum>=f)low=mid;
        else high=mid;
      }
      printf("%.4f\n",mid);
    }
  }
}
