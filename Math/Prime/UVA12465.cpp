/*************************************************************************
    > File Name: UVA12465.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 5日 23:09:03
 ************************************************************************/
#include<cstdio>
#include<cmath>
using namespace std;
const int MAXN=46341;
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
  int ans=1;
  for(int i=0;i<k&&n>1;i++){
    int cnt=0;
    if(n%prime[i]==0){
      while(n%prime[i]==0)n/=prime[i],cnt++;
    }
    ans*=(cnt+1);
  }
  if(n>1)ans*=2;
  return ans;
}
int main(){
  int a,b;
  sieve();
  while(~scanf("%d%d",&a,&b)&&a&&b){
    printf("%d\n",euler(abs(a-b)));
  }
}
