/*************************************************************************
     File Name: J.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 四 10/ 6 13:03:21 2016
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
using namespace std;
const int N=210;
int st[N],pa[N],cnt_s[N],cnt_p[N];

int main() {
  int t,n,m,i,j;
  cin>>t;
  for (int nc=1; nc<=t; ++nc) {
    cin>>n>>m;
    for (i=0; i<n; ++i) cin>>st[i];
    for (i=0; i<m; ++i) cin>>pa[i];
    sort(st,st+n);
    sort(pa,pa+m);
    cnt_s[0]=1;
    for (i=1,j=0; i<n; ++i) {
      if (st[i]==st[i-1]) cnt_s[j]++;
      else cnt_s[++j]=1;
    }
    n=j+1;
    cnt_p[0]=1;
    for (i=1,j=0; i<m; ++i) {
      if (pa[i]==pa[i-1]) cnt_p[j]++;
      else cnt_p[++j]=1;
    }
    m=j+1;
    bool flag=1;
    for (i=j=0; i<n; ++i,++j) {
      while (j<m && cnt_p[j]<cnt_s[i]) j++;
      if (j>=m) {
        flag=0;
        break;
      }
    }
    if (flag) cout<<"YES\n";
    else cout<<"NO\n";
  }
}
