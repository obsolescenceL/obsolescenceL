/*************************************************************************
     File Name: b.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月16日 星期一 21时02分06秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int mod=10007,n=4;
struct Mat{
  int mat[4][4];
}A,B,E;

void init(){
  for(int i=0;i<n;++i)E.mat[i][i]=1;
}

Mat operator * (Mat a,Mat b){
  Mat ans;
  memset(ans.mat,0,sizeof ans.mat);
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      for(int k=0;k<n;++k)
        if(a.mat[i][k]&&b.mat[k][j])
          ans.mat[i][j]=(ans.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
  return ans;
}

Mat operator ^ (Mat a,int x){
  Mat ans=E;
  for(;x;x>>=1){
    if(x&1)ans=ans*a;
    a=a*a;
  }
  return ans;
}

int main(){
  int t,m,a,b,c,i;
  init();
  B.mat[3][0]=1;
  while(~scanf("%d",&t)){
    for(i=1;i<=t;++i){
      scanf("%d%d%d%d",&m,&a,&b,&c);
      //cout<<m<<' '<<a<<' '<<b<<' '<<c<<endl;
      memset(A.mat,0,sizeof A.mat);
      //B.mat[2][0]=c;
      //cout<<B.mat[2][0]<<endl;
      //B.mat[1][0]=c*(a+1);
      //B.mat[0][0]=a*c*(a+1)+c;
      //cout<<B.mat[0][0]<<endl;
      if(m<=2){
        printf("Case %d: 0\n",i);
        continue;
      }
      A.mat[0][0]=a;
      A.mat[0][2]=b;
      A.mat[0][3]=c;
      A.mat[1][0]=A.mat[2][1]=A.mat[3][3]=1;
      A=A^(m-2);
      A=A*B;
      printf("Case %d: %d\n",i,A.mat[0][0]);
    }
  }
}
