/*************************************************************************
     File Name: i.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月15日 星期日 13时28分38秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int M=1000000;
int p[M+10],k=0,ans[M];
bool flag[3*M+8];

void sieve(){
  for(int i=2;i<=3*M+7;++i){
    if(!flag[i])p[k++]=i;
    for(int j=0;i*p[j]<=3*M+7;++j){
      flag[i*p[j]]=1;
      if(i%p[j]==0)break;
    }
  }
  for(int i=1;i<=M;++i){
    ans[i]=ans[i-1];
    if(!flag[3*i+7])ans[i]++;
  }
}

int main(){
  int t,n;
  sieve();
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&n);
      printf("%d\n",ans[n]);
    }
  }
}
