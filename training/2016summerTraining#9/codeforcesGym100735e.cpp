/*************************************************************************
     File Name: E.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月01日 星期一 13时11分28秒
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
ll a[N][N],row[N];

int main() {
  int n,i,j;
  ios::sync_with_stdio(0);
  while (cin>>n) {
    ll sum=0;
    for (i=0; i<n; ++i)
      for (j=0; j<n; ++j) {
        cin>>a[i][j];
        sum+=a[i][j];
        row[i]+=a[i][j];
      }
    sum/=n-1;
    for (i=0; i<n; ++i) {
      a[i][i]=sum-row[i];
      for (j=0; j<n; ++j)
        cout<<a[i][j]<<" \n"[j==n-1];
    }
  }
}