/*************************************************************************
     File Name: H.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 三 10/ 5 15:40:46 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<iostream>
using namespace std;
const int N=2e4+10;
typedef long long ll;
int s[N],p;

int main() {
  int t,n,m,i,j;
  cin>>t;
  for (int nc=1; nc<=t; ++nc) {
    multiset<int> ms,ms2;
    cin>>n>>m;
    for (i=0; i<n; ++i) cin>>s[i];
    for (i=0; i<m; ++i) {
      cin>>p;
      ms.insert(p);
    }
    if (m>n) {
      cout<<"0\n";
      continue;
    }
    ll ans=0;
    int diff_cnt=m;

    for (i=0; i<m; ++i) {
      if (ms.count(s[i])) {
        diff_cnt--;
        ms.erase(ms.find(s[i]));
      } else {
        diff_cnt++;
        ms2.insert(s[i]);
      }
    }
    if (!diff_cnt) ans++;

    for (i=m; i<n; ++i) {
      if (ms.count(s[i])) {
        diff_cnt--;
        ms.erase(ms.find(s[i]));
      } else {
        diff_cnt++;
        ms2.insert(s[i]);
      }
      if (ms2.count(s[i-m])) {
        diff_cnt--;
        ms2.erase(ms2.find(s[i-m]));
      } else {
        diff_cnt++;
        ms.insert(s[i-m]);
      }
      if (!diff_cnt) {
        ll tmp=i-m+2;
        ans+=tmp*tmp;
      }
    }
    cout<<ans<<endl;
  }
}
