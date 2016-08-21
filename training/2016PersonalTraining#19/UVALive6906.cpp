/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日  8/21 12:58:07 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=110;
int a[N];

int main() {
  int t,n,nn,k,i;
  while (~scanf("%d",&t)) {
    for (int nc=1; nc<=t; ++nc) {
      scanf("%d%d",&n,&k);
      nn=n;
      for (i=0; i<n; ++i) scanf("%d",a+i);
      sort(a,a+n);
      for (i=0; i<n-1; ++i)
        if (a[i+1]-a[i]<=k) nn--;
      printf("Case #%d: %d\n",nc,nn);
    }
  }
}
