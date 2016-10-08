/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 三 10/ 5 12:28:03 2016
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
#include<vector>
#include<map>
using namespace std;
const int N=1010;
bool flag[N];
int p[N/3],k=0;

void sieve() {
  for (int i=2; i<N; ++i) {
    if (!flag[i]) p[k++]=i;
    for (int j=0; i*p[j]<N; ++j) {
      flag[i*p[j]]=1;
      if (i%p[j]==0) break;
    }
  }
}

int main() {
  int t,n,a,b,i;
  sieve();
  cin>>t;
  for (int nc=1; nc<=t; ++nc) {
    cin>>n>>a>>b;
    int cnt_a=1,cnt_b=1;
    for (i=3; i<=n; ++i) {
      int tmp=cnt_b;
      cnt_b=cnt_a+cnt_b;
      cnt_a=tmp;
    }
    map<int,int> mp;
    vector<int> v;
    for (i=0; i<k; ++i) {
      while (a%p[i]==0) {
        a/=p[i];
        if (!mp.count(p[i])) v.pb(p[i]);
        mp[p[i]]+=cnt_a;
      }
      while (b%p[i]==0) {
        b/=p[i];
        if (!mp.count(p[i])) v.pb(p[i]);
        mp[p[i]]+=cnt_b;
      }
    }
    for (i=0; i<v.size(); ++i)
      cout<<v[i]<<' '<<mp[v[i]]<<endl;
    cout<<endl;
  }
}
