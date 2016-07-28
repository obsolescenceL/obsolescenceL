/*************************************************************************
     File Name: F.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月28日 星期四 22时05分04秒
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
const int N=110,M=1e5+10,INF=0x3f3f3f3f;
struct node{
  int a,b;
  bool operator < (const node &rhs) const {
    return b<rhs.b;
  }
}t[N];
bool f[M];

int main() {
  int n,i,j;
  while (~scanf("%d",&n)) {
    int maxn=0,minn=INF,min_dis=INF;
    for (i=0; i<n; ++i) {
      scanf("%d%d",&t[i].a,&t[i].b);
      minn=Min(minn,t[i].a);
      maxn=Max(maxn,t[i].b);
      min_dis=Min(min_dis,t[i].b-t[i].a);
    }
    sort(t,t+n);
    int low=0,high=Min(min_dis,(maxn-minn)/n),mid,ans=0;
    while (low<=high) {
      Mem0(f);
      mid=(low+high)>>1;
      //cout<<"low="<<low<<" high="<<high<<" mid="<<mid<<endl;
      int cnt,flag=0;
      for (i=0; i<n; ++i) {
        cnt=0;
        for (j=t[i].a; j<t[i].a+mid+cnt; ++j)
          if (f[j]) cnt++;
          else f[j]=1;
        if (j>t[i].b) flag=1;
      }
      if (!flag) low=mid+1,ans=mid;
      else high=mid-1;
    }
    printf("%d\n",ans*n);
  }
}
