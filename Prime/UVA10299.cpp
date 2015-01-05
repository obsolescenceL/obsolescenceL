/*************************************************************************
    > File Name: F.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 4日 15:49:23
 ************************************************************************/
#include<cstdio>
const int MAXN=31623;
bool flag[MAXN];
int prime[MAXN/3],k=0;
void sieve(){
  for(int i=2;i<MAXN;i++){
    if(!flag[i])prime[k++]=i;
    for(int j=0;i*prime[j]<MAXN;j++){
      flag[i*prime[j]]=1;
      if(i%prime[j]==0)break;
    }
  }
}
int main(){
  int n,i,j;
  sieve();
  while(~scanf("%d",&n)&&n){
    if(n==1){
      puts("0");
      continue;
    }
    int ans=n;
    for(i=0;i<k&&n>1;i++){
      if(n%prime[i]==0){
        ans=ans/prime[i]*(prime[i]-1);
        while(n%prime[i]==0)n/=prime[i];
      }
    }
    if(n>1)ans=ans/n*(n-1);
    printf("%d\n",ans);
  }
}
