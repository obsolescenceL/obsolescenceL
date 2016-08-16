/*************************************************************************
     File Name: d7.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月22日 星期日 18时10分01秒
 ************************************************************************/
#include<cstring>
#include<iostream>
using namespace std;
const int mod=2009,n=4;
struct Mat{
  int mat[n][n];
}A,B,C,E;

void init(){
  for(int i=0;i<n;++i)
    E.mat[i][i]=1;
}

Mat operator * (Mat a,Mat b){
  Mat c;
  memset(c.mat,0,sizeof c.mat);
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      for(int k=0;k<n;++k)
        c.mat[i][j]=(c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
  return c;
}

Mat operator ^ (Mat a,int x){
  Mat ans=E;
  for(;x;x>>=1){
    if(x&1)ans=ans*a;
    a=a*a;
  }
  return ans;
}
/*
Mat sum(int x){
  if(x==1)
    return A;
  if(x&1)
    return (A^x)+sum(x-1);
  else return sum(x/2)*((A^(x/2))+E);
}
*/
int main(){
  ios::sync_with_stdio(false);
  int m,t;
  init();
  B.mat[0][0]=4;
  B.mat[1][0]=5;
  B.mat[2][0]=3;
  B.mat[3][0]=1;
  A.mat[1][1]=3,A.mat[1][2]=2,A.mat[1][3]=7;
  A.mat[0][0]=A.mat[0][1]=A.mat[2][1]=A.mat[3][2]=1;
  while(cin>>t){
    for(int i=1;i<=t;++i){
      cin>>m;
      if(!m){
        cout<<"Case "<<i<<": 1"<<'\n';
        continue;
      }
      cout<<"Case "<<i<<": ";
      C=A^(m-1);
      C=C*B;
      cout<<C.mat[0][0]<<'\n';
    }
  }
}
