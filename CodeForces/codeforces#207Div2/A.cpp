/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月29日 星期五 09时51分42秒
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
int a[N];

int main() {
  int x,y,i,n;
  while (~scanf("%d",&n)) {
    int sum=0;
    for (i=1; i<=n; ++i) {
      scanf("%d",a+i);
      sum+=a[i];
    }
    scanf("%d%d",&x,&y);
    int tmp=0,ans=0;
    for (i=1; i<=n; ++i) {
      tmp+=a[i];
      if (tmp>=x && tmp<=y && sum-tmp>=x && sum-tmp<=y) {
        ans=i+1;
        break;
      }
    }
    printf("%d\n",ans);
  }
}
