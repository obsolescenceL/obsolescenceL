/*************************************************************************
     File Name: I.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月10日 星期三 15时42分37秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define LL long long
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=10010;
const LL INF=0x3f3f3f3f3f3f3f3f;
LL a[5][N];

int main() {
  int n,x,y,i,nc=0,pos;
  ios::sync_with_stdio(0);
  while (cin>>n>>x>>y && (n||x||y)) {
    cout<<"Case "<<++nc<<":\n";
    LL min_a1=INF,min_a2=INF;;
    for (i=1; i<=n; ++i) {
      cin>>a[1][i];
      min_a1=MIN(min_a1,a[1][i]);
    }
    for (i=1; i<=n; ++i) {
      cin>>a[2][i];
      if (min_a2>a[2][i]) {
        min_a2=a[2][i];
        pos=i;
      }
    }
    if (min_a1<min_a2) cout<<"INVALID\n";
    else {
      LL ans=min_a2*n*2;
      if (x==2) {
        for (i=MAX(y,pos); i>=pos; --i)
          if (a[2][i]==min_a2) break;
        pos=i;
        if (pos<=y) {
          ans+=y-pos;
          for (i=1; i<=n; ++i)
            a[1][i]-=min_a2;
          for (i=1; i<pos;++i)
            a[2][i]-=min_a2;
          for (i=pos+1; i<=y; ++i)
            a[2][i]-=min_a2+1;
          for (i=y+1; i<=n; ++i)
            a[2][i]-=min_a2;
        } else {
          ans+=2*n-pos+y;
          for (i=1; i<=n; ++i)
            a[1][i]-=min_a2+1;
          for (i=1; i<=y;++i)
            a[2][i]-=min_a2+1;
          for (i=y+1; i<pos; ++i)
            a[2][i]-=min_a2;
          for (i=pos+1; i<=n; ++i)
            a[2][i]-=min_a2+1;
        }
      } else {
        ans+=n-y+1+n-pos;
        for (i=1; i<y; ++i)
          a[1][i]-=min_a2;
        for (i=y; i<=n; ++i)
          a[1][i]-=min_a2+1;
        for (i=1; i<pos; ++i)
          a[2][i]-=min_a2;
        for (i=pos+1; i<=n; ++i)
          a[2][i]-=min_a2+1;
      }
      a[2][pos]=ans;
      bool flag=1;
      for (i=1; i<=n && flag; ++i) {
        if (a[1][i]<0) flag=0;
        if (a[2][i]<0) flag=0;
      }
      if (!flag) {
        cout<<"INVALID\n";
        continue;
      }
      for (i=1; i<=n; ++i)
        cout<<a[1][i]<<" \n"[i==n];
      for (i=1; i<=n; ++i)
        cout<<a[2][i]<<" \n"[i==n];
    }
  }
}
