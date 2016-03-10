/*************************************************************************
     File Name: HDU1730.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月17日 星期日 14时04分28秒
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
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;

int main(){
  int n,m,i,sum,t,j;
  while(~scanf("%d%d",&n,&m)){
    sum=0;
    for(i=0;i<n;++i){
      scanf("%d%d",&t,&j);
      int tmp=t-j;
      if(tmp<0)tmp=-tmp;
      tmp-=1;
      sum^=tmp;
    }
    if(sum)puts("I WIN!");
    else puts("BAD LUCK!");
  }
}
