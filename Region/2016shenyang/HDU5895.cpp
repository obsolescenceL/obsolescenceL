/*************************************************************************
     File Name: 1004.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日  9/18 15:29:16 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
const int M=5;
using namespace std;
const int PP = 100010 ;
typedef long long LL ;

LL prime[PP],ph ;
int cnt ;
bool is_p[PP];

int n;
struct Mat{
  LL mat[M][M];
  void debug(){
    for (int i=0;i<n;++i){
      for (int j=0;j<n;++j)
        printf("%lld ",mat[i][j]);
      puts("");
    }
  }
}D,F,E;

void init(){
  for (int i=0;i<n;++i)
    E.mat[i][i]=1;
  //cout<<"E.mat[0][0]="<<E.mat[0][0]<<endl;
}

Mat operator * (Mat a,Mat b){
  Mat c;
  memset(c.mat,0,sizeof c.mat);
  for (int i=0;i<n;++i)
    for (int j=0;j<n;++j)
      for (int k=0;k<n;++k)
        if (a.mat[i][k]&&b.mat[k][j])
          c.mat[i][j]=(c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%ph;
  return c;
}

Mat operator ^ (Mat a,LL x){
  Mat c=E;
  //c.debug();
  for(;x;x>>=1){
    if(x&1)c=c*a;
    a=a*a;
  }
  return c;
}

void calc(){
  for (int i=1;i<PP;i++)   is_p[i] = 1 ;
  cnt = 0 ;
  for (LL i=2; i<PP; i++)
    if (is_p[i]){
      prime[cnt ++] = i ;
      for (LL j=2 ; i*j<PP ;j ++ ){
        is_p[i*j] = 0 ;
      }
    }
}

LL get_phi(LL c){
  LL res = c ;
  for (int i=0; i<cnt && prime[i]*prime[i] <= c; i++ ){
    if (c%prime[i] == 0){
      res = res/prime[i]*(prime[i]-1) ;
      while (c%prime[i] == 0)    c /= prime[i] ;
    }
  }
  if (c>1) res = res / c * (c - 1) ;
  return res ;
}

LL Pow(LL a,LL b,LL p){
  LL res = 1 , add = a % p ;
  while (b){
    if (b&1) res = res * add % p ;
    add = add * add % p ;
    b >>= 1 ;
  }
  return res ;
}

int main(){
  n=4;
  LL B,nn,y,A,C,ans;
  calc();
  init();
  int t;
  scanf("%d",&t);
  while (t--) {
    scanf("%lld%lld%lld%lld",&nn,&y,&A,&C);
    C++;
    MEM0(D.mat);
    D.mat[0][0]=D.mat[0][1]=1;
    D.mat[1][2]=1,D.mat[1][1]=D.mat[1][3]=4;
    D.mat[2][1]=1;
    D.mat[3][1]=2,D.mat[3][3]=1;
    F.mat[0][0]=0,F.mat[1][0]=1,F.mat[2][0]=0,F.mat[3][0]=0;
    if (nn*y <= 10l) {
      D=D^(nn*y);
      F=D*F;
      B=F.mat[0][0];
      ans = Pow(A,B,C);
    } else {
      ph = get_phi(C) ;
      //cout<<"nn*y="<<nn*y<<endl;
      D=D^(nn*y);
      //D.debug();
      F=D*F;
      //cout<<"ph="<<ph<<endl;
      //F.debug();
      B=F.mat[0][0]%ph;
      ans = Pow(A,B+ph,C);
    }
    printf("%lld\n",ans) ;
  }
}
