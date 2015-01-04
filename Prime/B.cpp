/*************************************************************************
    > File Name: B.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 4日 22:27:09
 ************************************************************************/
#include<cstdio>
#include<cmath>
const int MAXN=46340;
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
int euler(int n){
  int ans=n,ans1=1;
  for(int i=0;i<k&&sqrt(n)>prime[i];i++){
    int cnt=0;
    if(n%prime[i]==0){
      ans=ans/prime[i]*(prime[i]-1);
      while(n%prime[i]==0){
        n/=prime[i];
        cnt++;
      }
    }
    ans1*=(cnt+1);
  }
  if(n>1){
    ans=ans/n*(n-1);
    ans1*=2;
  }
  return ans1+ans-1;
}

int main(){
  int n;
  sieve();
  while(~scanf("%d",&n)){
    int ans=euler(n);
    printf("%d\n",n-ans);
  }
}
