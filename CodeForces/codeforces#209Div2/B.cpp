/*************************************************************************
     File Name: B.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月25日 星期一 09时23分04秒
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
const int N=50010;
int ans[N<<1];

int main(){
  int n,k,i;
  while(~scanf("%d%d",&n,&k)){
    n<<=1;
    for(i=1;i<=n;++i) ans[i]=i;
    for(i=1;i<=k;++i)
      swap(ans[2*i-1],ans[2*i]);
    for(i=1;i<=n;++i)
      printf("%d%c",ans[i],i==n?'\n':' ');
  }
}
