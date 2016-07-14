/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月14日 星期四 09时43分14秒
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

int main(){
  int n,i;
  ll x;
  while(~scanf("%d",&n)){
    ll sum=0,ans=0;
    for(i=0;i<n;++i){
      scanf("%I64d",&x);
      sum+=x;
      ans=Max(ans,x);
      //cout<<"sum="<<sum<<endl;
    }
    ans=Max(ans,(sum+n-2)/(n-1));
    printf("%I64d\n",ans);
  }
}
