/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月11日 星期三 16时07分06秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int mod=10000;
struct Matrix{
  int mat[2][2];
}A,E;

void init(){
  for(int i=0;i<2;i++)
    E.mat[i][i]=1;
}

Matrix operator * (Matrix a,Matrix b){
  Matrix ans;
  memset(ans.mat,0,sizeof ans.mat);
  for(int i=0;i<2;++i)
    for(int j=0;j<2;++j)
      for(int k=0;k<2;++k)
        if(a.mat[i][k]&&b.mat[k][j])
          ans.mat[i][j]=(ans.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
  return ans;
}

Matrix operator ^ (Matrix a,int x){
  Matrix ans=E;
  for(;x;x>>=1){
    if(x&1)ans=ans*a;
    a=a*a;
  }
  return ans;
}

int main(){
  int n;
  init();
  while(~scanf("%d",&n)&&n!=-1){
    A.mat[0][0]=A.mat[0][1]=A.mat[1][0]=1;
    A.mat[1][1]=0;
    A=A^n;
    printf("%d\n",A.mat[0][1]);
  }
}
