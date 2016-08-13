/*************************************************************************
     File Name: c.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月28日 星期二 21时00分52秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
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
int m[70];

int main(){
  ll n;
  int ans,i,j;
  while(~scanf("%lld",&n)){
    Mem0(m);
    ans=1;
    for(i=60;i>=2;--i){
      m[i]=(int)pow(n,1.0/i)-1;
      for(j=i*2;j<=60;j+=i)m[i]-=m[j];
      ans+=m[i];
    }
    printf("%d\n",ans);
  }
}
