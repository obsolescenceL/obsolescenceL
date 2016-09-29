/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五  9/23 20:59:41 2016
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
using namespace std;
const int N=110;
int a[N];

int main() {
  int n,i;
  while (cin>>n) {
    for (i=1; i <= n; ++i)
      cin>>a[i];
    if (n==1 && a[n]!=15 && a[n]!=0) cout<<"-1\n";
    else if (a[n]==0 || (a[n]>a[n-1] && a[n]!=15)) cout<<"UP\n";
    else cout<<"DOWN\n";
  }
}
