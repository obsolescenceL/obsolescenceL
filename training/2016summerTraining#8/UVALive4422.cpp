/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月31日 星期日 11时59分30秒
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

int main(){
  int n,t1,t2,t3;
  while (~scanf("%d%d%d%d",&n,&t1,&t2,&t3)) {
    if (!n && !t1 && !t2 && !t3) break;
    double ans=3*n+(t2-t1+n)%n+(t2-t3+n)%n;
    ans+=(n-1.0)/2.0;
    printf("%.3lf\n",ans);
  }
}
