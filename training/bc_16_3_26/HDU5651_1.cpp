/*************************************************************************
     File Name: HDU5651_1.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 四  3/31 20:08:34 2016
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
const int N=1010,M=30,mod=1e9+7;
char s[N];
ll fac[N],inv[N],cnt[M];

ll Pow(ll x,ll k){
  ll ans=1;
  for(;k;k>>=1){
    if(k&1)ans=ans*x%mod;
    x=x*x%mod;
  }
  return ans;
}

void init(){
  int i;
  fac[0]=1;
  for(i=1;i<N;++i)
    fac[i]=fac[i-1]*i%mod;
  inv[N-1]=Pow(fac[N-1],mod-2);
  for(i=N-2;i>=0;--i)
    inv[i]=inv[i+1]*(i+1)%mod;
}

int main(){
  init();
  int t,i;
  ios::sync_with_stdio(0);
  while(cin>>t){
    while(t--){
      Mem0(cnt);
      cin>>s;
      //cout<<"s="<<s<<endl;
      int n=strlen(s);
      for(i=0;i<n;++i)cnt[s[i]-'a']++;
      int flag=2;
      for(i=0;i<=26;++i){
        if(cnt[i]%2)flag--;
        cnt[i]/=2;
        //if(cnt[i])cout<<"cnt["<<i<<"]="<<cnt[i]<<endl;
      }
      if(flag>0){
        ll ans=fac[n/2];
        for(i=0;i<=26;++i)
          ans=ans*inv[cnt[i]]%mod;
        cout<<ans<<endl;
      }else cout<<"0\n";
    }
  }
}
