/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  4/ 2 13:03:56 2016
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
const int N=2010;
ll dis1[N],dis2[N];

int main(){
  int n,i,j;
  ll x1,y1,x2,y2,x,y;
  ios::sync_with_stdio(0);
  while(cin>>n>>x1>>y1>>x2>>y2){
    ll max_d2=0;
    for(i=0;i<n;++i){
      cin>>x>>y;
      dis1[i]=(x-x1)*(x-x1)+(y-y1)*(y-y1);
      dis2[i]=(x-x2)*(x-x2)+(y-y2)*(y-y2);
      max_d2=Max(max_d2,dis2[i]);
    }
    ll ans=max_d2;
    for(i=0;i<n;++i){
      max_d2=0;
      for(j=0;j<n;++j){
        if(i==j)continue;
        if(dis1[j]>dis1[i])
          max_d2=Max(max_d2,dis2[j]);
      }
      ans=Min(ans,dis1[i]+max_d2);
    }
    cout<<ans<<endl;
  }
}
