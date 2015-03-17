/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月12日 星期四 09时07分34秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
const int mod=9973;
const int M=15;
using namespace std;
int n;
struct Mat{
  //int r,c;
  int mat[M][M];
  //int* operator [] (int i){
    //return mat[i];
  //}
  //const int* operator [] (int i)const{
    //return mat[i];
  //}
  //void init(int row,int col){
    //this->r=row;
    //this->c=col;
  //}
  //void fill(int row,int col,int x=0){
    //init(row,col);
    //for(int i=0;i<r;++i)
      //::fill(mat[i],mat[i]+c,x);
  //}
  //void eye(int n,int x=1){
    //fill(n,n,0);
    //for(int i=0;i<n;++i)
      //mat[i][i]=x;
  //}
  //void set(const Mat& o){
    //init(o.r,o.c);
    //for(int i=0;i<r;++i)
      //copy(o[i],o[i]+c,mat[i]);
  //}
  void debug(){
    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j)
        printf("%d ",mat[i][j]);
      puts("");
    }
  }
}A,E;

void init(){
  for(int i=0;i<n;++i)
    E.mat[i][i]=1;
  //cout<<"E.mat[0][0]="<<E.mat[0][0]<<endl;
}

Mat operator * (Mat a,Mat b){
  Mat c;
  memset(c.mat,0,sizeof c.mat);
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      for(int k=0;k<n;++k)
        if(a.mat[i][k]&&b.mat[k][j])
          c.mat[i][j]=(c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
  return c;
}

Mat operator ^ (Mat a,int x){
  Mat c=E;
  //c.debug();
  for(;x;x>>=1){
    if(x&1)c=c*a;
    a=a*a;
  }
  return c;
}

int main(){
  int t,k,i,j;
  while(~scanf("%d",&t)){
    while(t--){
      memset(A.mat,0,sizeof A.mat);
      scanf("%d%d",&n,&k);
      init();
      for(i=0;i<n;++i)
        for(j=0;j<n;++j)
          scanf("%d",&A.mat[i][j]);
      A=A^k;
      int sum=0;
      //cout<<"n="<<n<<endl;
      for(i=0;i<n;++i){
        sum+=A.mat[i][i];
        //cout<<"sum="<<sum<<endl;
      }
      sum%=mod;
      printf("%d\n",sum);
    }
  }
}
