/*************************************************************************
     File Name: B.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月28日 星期四 14时01分33秒
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
const int N=4010;
struct node{
  ll a,b;
  bool operator < (const node &rhs) const {
    return a < rhs.a;
  }
}cake[N];
ll b[N];

int main() {
  int n,i,j,k;
  while (cin>>n) {
    for (i=0; i<n; ++i) {
      cin>>cake[i].a>>cake[i].b;
      if (cake[i].a<cake[i].b)
        swap(cake[i].a,cake[i].b);
    }
    sort(cake,cake+n);
    ll ans=0,tmp,ansA,ansB;
    for (i=0; i<n; ++i) {
      for (j=i,k=0; j<n; ++j)
        b[k++]=cake[j].b;
      sort(b,b+k);
      for (j=0; j<k; ++j) {
        tmp=cake[i].a*b[j]*(k-j);
        if (ans<tmp) {
          ans=tmp;
          ansA=cake[i].a;
          ansB=b[j];
        }
      }
    }
    cout<<ans<<'\n'<<ansA<<' '<<ansB<<'\n';
  }
}
