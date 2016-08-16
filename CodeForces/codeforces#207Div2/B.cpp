/*************************************************************************
     File Name: B.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月29日 星期五 10时06分47秒
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
const int N=1e5+10;
struct node{
  int a[4];
}d[N];
int ans[N];

int main() {
  int n,m,i,j,k;
  bool flag[4];
  while (~scanf("%d%d",&n,&m)) {
    Mem0(ans);
    for (i=0; i<m; ++i) {
      for (j=1; j<=3; ++j)
        scanf("%d",&d[i].a[j]);
      Mem0(flag);
      for (j=1; j<=3; ++j)
        flag[ans[d[i].a[j]]]=1;
      for (k=1; k<=3; ++k)
        if (!ans[d[i].a[k]]) {
          for (j=1; j<=3; ++j)
            if (!flag[j]) {
              ans[d[i].a[k]]=j;
              flag[j]=1;
              break;
            }
        }
    }
    for (i=1; i<=n; ++i)
      printf("%d%c",ans[i],i==n?'\n':' ');
  }
}
