/*************************************************************************
     File Name: HDU1757.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月04日 星期三 21时52分38秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
const int M=15;
const int n=10;
struct Matrix{
  long long mat[M][M];
}E,A;
int mod;

void init(){
  for(int i=0;i<n;++i)
    E.mat[i][i]=1;
}

Matrix operator * (Matrix mat1,Matrix mat2){
  Matrix ans;
  memset(ans.mat,0,sizeof ans.mat);
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      for(int k=0;k<n;++k)
        ans.mat[i][j]=(ans.mat[i][j]+mat1.mat[i][k]*mat2.mat[k][j])%mod;
  return ans;
}

Matrix operator ^ (Matrix mat1,int x){
  Matrix ans=E;
  for(;x;x>>=1){
    if(x&1)ans=ans*mat1;
    mat1=mat1*mat1;
  }
  return ans;
}

int main(){
  int k,i,a[M];
  init();
  while(~scanf("%d%d",&k,&mod)){
    for(i=0;i<n;++i)
      scanf("%d",a+i);
    if(k<n){
      printf("%d\n",k);
      continue;
    }
    memset(A.mat,0,sizeof A.mat);
    for(i=0;i<n;++i)A.mat[i][0]=a[i];
    for(i=1;i<n;++i)A.mat[i-1][i]=1;
    A=A^(k-9);
    long long ans=0;
    for(i=0;i<n;++i)
      ans=(ans+(9-i)*A.mat[i][0])%mod;
    printf("%I64d\n",ans);
  }
}
