/*************************************************************************
     File Name: 1007.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  9/17 14:25:54 2016
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
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=1e5+10;
LL v[N];
queue<LL> q1,q2;

int main() {
  ios::sync_with_stdio(0);
  int T,n,i,j,ans;
  LL sum,tmp,t;
  cin>>T;
  while (T--) {
    cin>>n>>t;
    for (i=1; i<=n; ++i) cin>>v[i];
    sort(v+1,v+n+1);

    ans=n;
    int low=2,high=n,mid,tmp1;
    while (low<=high) {
      mid=(low+high)>>1;
      while (!q1.empty()) q1.pop();
      while (!q2.empty()) q2.pop();

      for (i=1; i<=n; ++i) q1.push(v[i]);
      sum=tmp=0;

      tmp1=(n-1)%(mid-1);
      if (tmp1) {
        for (i=0; i<=tmp1 && (!q1.empty() || !q2.empty()); ++i) {
          if (!q2.empty() && (q1.empty() || q2.front()<=q1.front())) tmp+=q2.front(),q2.pop();
          else tmp+=q1.front(),q1.pop();
        }
        if (!q1.empty() || !q2.empty()) q2.push(tmp);
        sum+=tmp;
      }
      while (!q1.empty() || !q2.empty()) {
        tmp=0;
        for (i=0; i<mid && (!q1.empty() || !q2.empty()); ++i) {
          if (!q2.empty() && (q1.empty() || q2.front()<=q1.front())) tmp+=q2.front(),q2.pop();
          else tmp+=q1.front(),q1.pop();
        }
        if (!q1.empty() || !q2.empty()) q2.push(tmp);
        sum+=tmp;
        //cout<<"tmp="<<tmp<<endl;
      }
      //cout<<"mid="<<mid<<" sum="<<sum<<endl;

      if (sum <= t) high=mid-1,ans=mid;
      else low=mid+1;
    }
    if (n>1) cout<<ans<<endl;
    else cout<<"0\n";
  }
}
