/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月29日 星期三 15时04分54秒
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
const int N=10010;
struct node{
  int cnt,v;
  bool operator < (const node & rhs) const {
    return cnt>rhs.cnt||(cnt==rhs.cnt && v>rhs.v);
  }
}cc[N];
int v[N];

int main(){
  int t,n,m,c,x,i,nc;
  while(~scanf("%d",&t)){
    for(nc=1;nc<=t;++nc){
      Mem0(cc);
      scanf("%d%d%d",&m,&n,&c);
      while(m--){
        scanf("%d",&x);
        cc[x].cnt++;
        //cout<<"v["<<i<<"]="<<v[i]<<endl;
      }
      //cout<<"maxn="<<maxn<<endl;
      for(i=1;i<=n;++i)cc[i].v=(i*i)%c;
      sort(cc+1,cc+1+n);
      ll ans=0;
      for(i=1;i<=n;++i)
        cc[i].v+=cc[i-1].v;
      for(i=1;i<=n;++i)
        ans=Max(ans,cc[i].cnt*cc[i].v);
      printf("Case %d: %d\n",nc,ans);
    }
  }
}
