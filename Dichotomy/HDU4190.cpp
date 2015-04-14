/*************************************************************************
     File Name: HDU4190.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月06日 星期一 10时40分37秒
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
int a[500001];

int main(){
  int n,m,i,sum,max_vol;
  while(~scanf("%d%d",&n,&m)){
    if(n==-1&&m==-1)break;
    for(i=0;i<n;++i){
      scanf("%d",a+i);
      max_vol=Max(max_vol,a[i]);
    }
    int low=0,high=max_vol,mid;
    while(high>low+1){
      mid=(high+low)/2;
      sum=0;
      for(i=0;i<n;++i)
        sum+=(a[i]+mid-1)/mid;
      if(sum>m)low=mid;
      else high=mid;
    }
    printf("%d\n",high);
  }
}
