/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月12日 星期二 22时20分36秒
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
ll h[N],p[N],tim[N];

int main(){
  int n,m,i;
  ll ans;
  while(~scanf("%d%d",&n,&m)){
    for(i=0;i<n;++i)scanf("%I64d",h+i);
    for(i=0;i<m;++i)scanf("%I64d",p+i);
    ll low=0,high=Abs(p[0],h[0])*2+Abs(p[m-1],h[0]),mid;
    while(low<=high){
      mid=(low+high)>>1;
      int cur=0;
      ll f;
      for(i=0;i<n;++i){
        if(Abs(p[cur],h[i])>mid)continue;
        if(p[cur]==h[i])cur++;
        if(p[cur]<h[i])f=Max(h[i]+mid-2*(h[i]-p[cur]),h[i]+(mid-(h[i]-p[cur]))/2);
        else f=h[i]+mid;
        while(p[cur]<=f && cur<m)cur++;
      }
      if(cur<m)low=mid+1;
      else high=mid-1;
      //cout<<"low="<<low<<" high="<<high<<endl;
    }
    printf("%I64d\n",low);
  }
}
