/*************************************************************************
     File Name: I.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月14日 星期日 13时38分48秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>
#include<bitset>
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
const int mod=10000007,N=15;
int n,m;
struct Matrix{
  ll mat[N][N];
}E,A,B;

void init(){
  for(int i=0;i<N;++i)E.mat[i][i]=1;
}

Matrix operator *(Matrix x,Matrix y){
  Matrix ans;
  Mem0(ans.mat);
  int i,j,k;
  for(i=0;i<n+2;++i)
    for(j=0;j<n+2;++j)
      for(k=0;k<n+2;++k)
        ans.mat[i][j]=(ans.mat[i][j]+x.mat[i][k]*y.mat[k][j])%mod;
  return ans;
}

Matrix operator ^(Matrix a,int x){
  Matrix ans=E;
  for(;x;x>>=1){
    if(x&1)ans=ans*a;
    a=a*a;
  }
  return ans;
}

int main(){
  int i,j;
  init();
  while(~scanf("%d%d",&n,&m)){
    //cout<<"n="<<n<<" m="<<m<<endl;
    Mem0(A.mat);
    Mem0(B.mat);
    A.mat[0][0]=23;
    A.mat[n+1][0]=3;
    for(i=1;i<=n;++i)
      scanf("%I64d",&A.mat[i][0]);
    for(i=0;i<=n;++i)B.mat[i][0]=10;
    for(i=0;i<=n+1;++i)B.mat[i][n+1]=1;
    for(i=1;i<=n;++i)
      for(j=1;j<=i;++j)
        B.mat[i][j]=1;
    B=B^m;
    /*
    for(i=0;i<=n+1;++i){
      for(j=0;j<=n+1;++j)
        cout<<B.mat[i][j]<<' ';
      cout<<endl;
    }
    */
    A=B*A;
    /*
    for(i=0;i<=n+1;++i)
      cout<<A.mat[i][0]<<' ';
    cout<<endl;
    */
    printf("%I64d\n",A.mat[n][0]);
  }
}
