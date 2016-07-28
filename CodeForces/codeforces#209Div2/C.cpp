/*************************************************************************
     File Name: C.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月25日 星期一 09时42分49秒
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
const int INF=0x3f3f3f3f,mod=1e9+7;
const int N=1e5+10;
int t[N],tmp[N];

ll Pow(ll x,ll k){
  ll ans=1;
  for(;k;k>>=1){
    if(k&1)ans=ans*x%mod;
    x=x*x%mod;
  }
  return ans;
}

int main(){
  int n,x,i,cnt;
  while(~scanf("%d%d",&n,&x)){
    ll sum=0;
    map<int,int> mp;
    for(i=0;i<n;++i){
      scanf("%d",t+i);
      sum+=t[i];
      mp[t[i]]++;
    }
    ll minn=sum-t[n-1];
    for(i=t[n-1],cnt=0;i>0;--i){
      while(n && t[n-1]==i)n--,cnt++;
      if(cnt%x)break;
      minn++;
      cnt/=x;
    }
    printf("%I64d\n",Pow(x,minn));
  }
}
