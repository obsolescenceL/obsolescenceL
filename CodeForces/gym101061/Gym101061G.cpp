/*************************************************************************
     File Name: G.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五 10/ 7 12:38:09 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL mod=1000000007;

LL Pow(LL x,LL k,LL m) {
  LL ans=1;
  for (; k; k>>=1) {
    if (k&1) ans=ans*x%m;
    x=x*x%m;
  }
  return ans;
}

int main() {
  int t;
  LL n,m;
  cin>>t;
  for (int nc=1; nc<=t; ++nc) {
    cin>>n>>m;
    LL nn=m,len=0;
    while (nn) {
      nn/=10;
      len++;
    }
    LL q=Pow(10,len,mod);
    //cout<<"q="<<q<<endl;
    m=m*(Pow(q,n,mod)+(-1%mod))%mod*Pow(q-1,mod-2,mod)%mod;
    cout<<m<<endl;
  }
}
