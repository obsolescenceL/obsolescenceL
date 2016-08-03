/*************************************************************************
     File Name: D.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月02日 星期二 15时20分01秒
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
const int N=110;
struct node{
  int s,e;
  bool operator < (const node &rhs) const {
    return e<rhs.e || (e==rhs.e && s<rhs.s);
  }
}a[N];
int cnt[N];

int main() {
  int n,i,j,nc=0;
  while (~scanf("%d",&n)&&n) {
    for (i=0; i<n; ++i)
      scanf("%d%d",&a[i].s,&a[i].e);
    sort(a,a+n);
    Mem0(cnt);
    int ans=0;
    for (i=0; i<n; ++i)
      for (j=a[i].s; j<a[i].e; ++j)
        if (cnt[j]<2) {
          cnt[j]++;
          ans++;
          break;
        }
    printf("On day %d Emma can attend as many as %d parties.\n",++nc,ans);
  }
}

