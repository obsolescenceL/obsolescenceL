/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五 10/ 7 12:30:07 2016
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
const int INF=0x3f3f3f3f;

int main() {
  int t,i,a[10];
  cin>>t;
  for (int nc=1; nc<=t; ++nc) {
    for (i=0; i<5; ++i)
      cin>>a[i];
    sort(a,a+5,greater<int>());
    cout<<a[0]*a[1]<<endl;
  }
}
