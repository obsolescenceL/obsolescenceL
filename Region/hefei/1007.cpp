/*************************************************************************
     File Name: 1007.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年09月27日 星期日 12时08分47秒
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
  int t;
  init();
  while(~scanf("%d",&t)){
    for(int nc=1;nc<=t;++nc){
      scanf("%d%d%d%d%d%d",&b1,&q,&a1,&d,&n,&m);

