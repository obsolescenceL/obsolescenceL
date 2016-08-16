/*************************************************************************
     File Name: D.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月10日 星期三 12时35分29秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define LL long long
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const LL mod=1000000007;

LL Pow(LL x,LL k) {
  LL ans=1;
  for (; k; k>>=1) {
    if (k&1) ans=ans*x%mod;
    x=x*x%mod;
  }
  return ans;
}

LL C(LL m,LL n) {
  if (n<m) return 0;
  if (m>n-m) m=n-m;
  LL sum=1;
  for (int i=0; i<m; ++i) {
    sum=sum*(n-i)%mod;
    sum=sum*Pow(i+1,mod-2)%mod;
  }
  return sum;
}

int main() {
  int n,m,k,d,i,x,t;
  ios::sync_with_stdio(0);
  while (cin>>t) {
    while (t--) {
      cin>>n>>m>>k>>d;
      int cnt=0;
      for (i=0; i<n; ++i) {
        cin>>x;
        if (x>=d) cnt++;
      }
      //cout<<"cnt="<<cnt<<endl;
      LL sum=0;
      for (i=0; k+i<=cnt && k+i<=m; ++i) {//k+i<=m !!!
        LL tmp1=1,tmp2=1;
        if (k+i) tmp1=C(k+i,cnt);
        if (m-k-i) tmp2=C(m-k-i,n-cnt);
        sum+=tmp1*tmp2;
      }
      cout<<sum%mod<<endl;
    }
  }
}
