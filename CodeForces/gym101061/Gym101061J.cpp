/*************************************************************************
     File Name: J.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五 10/ 7 16:36:48 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
const int N=1e5+10,INF=0x3f3f3f3f;
typedef long long LL;
int c[N],l[N];

int main() {
  int t,i,x,y,n,m;
  cin>>t;
  for (int nc=1; nc<=t; ++nc) {
    set<int> s;
    set<int>::iterator it;
    cin>>n>>m;
    for (i=1; i<=n; ++i) {
      cin>>c[i];
      l[i]=c[i];
      s.insert(i);
    }
    s.insert(INF);
    LL ans=0;
    for (i=1; i<=m; ++i) {
      cin>>x>>y;
      //cout<<"-----x="<<x<<" y="<<y<<endl;
      while (y>0) {
        it=s.lower_bound(x);
        //cout<<"it="<<*it<<endl;
        if (*it==INF) {
          ans+=y;
          break;
        }
        if (c[*it]<=y) {
          y-=c[*it];
          c[*it]=0;
          s.erase(it);
        } else c[*it]-=y,y=0;
        //cout<<"y="<<y<<endl;
      }
    }
    cout<<ans<<endl;
    for (i=1; i<=n; ++i)
      cout<<(l[i]-c[i])<<" \n"[i==n];
  }
}
