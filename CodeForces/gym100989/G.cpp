/*************************************************************************
     File Name: G.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月18日 星期一 16时12分08秒
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
const int N=1e5+10;
ll a[N];

int main(){
  ll k,av,sum,sav,maxn;
  int i,m;
  ios::sync_with_stdio(0);
  while(cin>>m>>k){
    sum=maxn=0;
    for(i=0;i<m;++i){
      cin>>a[i];
      //cout<<"a["<<i<<"]="<<a[i]<<endl;
      sum+=a[i];
      maxn=Max(maxn,a[i]);
    }
    av=(sum+m-1)/m;
    ll low=av,high=maxn,mid,ans;
    while(low<=high){
      mid=(low+high)>>1;
      //cout<<"low="<<low<<" high="<<high<<" mid="<<mid<<endl;
      sav=0;
      for(i=0;i<m;++i){
        if(a[i]>mid)sav+=a[i]-mid;
      }
      //cout<<"sav="<<sav<<" k="<<k<<endl;
      if(sav<=k)ans=mid,high=mid-1;
      else low=mid+1;
    }
    cout<<ans<<endl;
  }
}
