/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月28日 星期六 17时17分25秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
const int INF=0x3F3F3F3F;
using namespace std;
int v[1010],dp[1010];

int main(){
  int i,j,n,m;
  while(~scanf("%d",&n)&&n){
    memset(dp,0,sizeof dp);
    memset(v,0,sizeof v);
    for(i=0;i<n;++i)scanf("%d",v+i);
    scanf("%d",&m);
    if(m<5){
      printf("%d\n",m);
      continue;
    }
    sort(v,v+n);
    int maxv=v[n-1];
    m-=5;
    //for(i=0;i<n;++i)dp[i]=m;
    for(i=0;i<n-1;++i){
      for(j=m;j>=v[i];--j){
        dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
      }
    }
    printf("%d\n",m+5-dp[m]-maxv);
  }
}
