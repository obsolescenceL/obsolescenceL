/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月11日 星期三 14时44分35秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
int x[100010];

int main(){
  int t,n,k,i,j;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d",&n,&k);
      for(i=0;i<n;++i)scanf("%d",x+i);
      sort(x,x+n);
      long long ans=0;
      for(i=0,j=0;i<n;++i){
        while(j+1<n&&x[j+1]-x[i]<=k)j++;
        ans+=j-i;
      }
      printf("%I64d\n",ans);
    }
  }
}
