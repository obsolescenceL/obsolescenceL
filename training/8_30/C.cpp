/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月30日 星期日 19时28分08秒
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
const int N=1e5+10;
int a[N];

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    for(i=0;i<n;++i){
      scanf("%d",&a[i]);
      while(a[i]%2==0)a[i]/=2;
      while(a[i]%3==0)a[i]/=3;
    }
    bool flag=1;
    for(i=0;i<n-1;++i)
      if(a[i]!=a[i+1]){flag=0;break;}
    if(flag)puts("YES");
    else puts("NO");
  }
}