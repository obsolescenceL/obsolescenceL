/*************************************************************************
     File Name: B.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月01日 星期一 14时19分12秒
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
const int N=30;
const ll mod=1e9+9L;
int n;
struct Mat{
  ll mat[N][N];
  void debug() {
    for (int i=0; i<n; ++i){
      for (int j=0; j<n; ++j)
        printf("%d ",mat[i][j]);
      puts("");
    }
  }
}A,B,E;

Mat operator * (Mat a,Mat b) {
  Mat c;
  Mem0(c.mat);
  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
      for (int k=0; k<n; ++k)
        if (a.mat[i][k] && b.mat[k][j])
          c.mat[i][j]=(c.mat[i][j]+a.mat[i][k]*b.mat[k][j]%mod)%mod;
  return c;
}

Mat operator ^ (Mat a,ll x) {
  Mat c=A;
  for (; x; x>>=1) {
    if (x&1) c=c*a;
    a=a*a;
  }
  return c;
}

int main() {
  ll m;
  int c,i,j,k;
  while (cin>>n>>m>>c) {
    Mem0(A.mat),Mem0(B.mat);
    for (i=0; i<n; ++i) {
      cin>>A.mat[0][i];
      B.mat[i+1][i]=1;
    }
    for (i=0; i<c; ++i) {
      cin>>k;
      B.mat[n-k][n-1]=1;
    }
    if (m<=n) {
      cout<<A.mat[0][m-1]%mod<<endl;
      continue;
    }
    A=B^(m-n);
    cout<<A.mat[0][n-1]%mod<<endl;
  }
}
