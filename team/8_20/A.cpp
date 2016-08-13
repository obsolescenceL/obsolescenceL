/*************************************************************************
     file name: a.cpp
     id: obsoles1
     prog: 
     lang: c++ 
     mail: 384099319@qq.com 
     created time: 2015年08月20日 星期四 13时30分47秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
#include<algorithm>
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
const int n=55,inf=0x3f3f3f3f;
int size[n];

int main(){
  int n,m,i,j,temp,min_diff;
  while(~scanf("%d%d",&n,&m)){
    for(i=0;i<m;++i)
      scanf("%d",&size[i]);
    sort(size,size+m);
    min_diff=inf;
    for(i=0;i<=m-n;++i)
      min_diff=min(min_diff,size[i+n-1]-size[i]);
    printf("%d\n",min_diff);
  }
}
