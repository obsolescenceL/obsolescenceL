/*************************************************************************
     File Name: J.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月04日 星期四 13时34分50秒
 ************************************************************************/
#include<bits/stdc++.h>
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
const int N=1e6+10;
const ll mod=1e9+7;
ll ans[N];

void pre() {
  ans[1]=ans[2]=1;
  ans[3]=3,ans[4]=11,ans[5]=53;
  for (int i=6; i<N; ++i)
    ans[i]=(ans[i-1]*((ll)i-1)+ans[i-2]*((ll)i-2))%mod;
}

int main() {
  ios::sync_with_stdio(0);
  int t,nc,i,n;
  pre();
  while (cin>>t) {
    for (nc=1; nc<=t; ++nc) {
      cin>>n;
      cout<<"Case "<<nc<<": "<<ans[n]<<'\n';
    }
  }
}
