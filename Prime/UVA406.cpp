/*************************************************************************
    > File Name: UVA406.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 5日 12:02:47
 ************************************************************************/
#include<cstdio>
const int MAXN=1010;
bool flag[MAXN];
int prime[MAXN/3],k=1;
void sieve(){
  for(int i=2;i<MAXN;i++){
    if(!flag[i])prime[k++]=i;
    for(int j=1;i*prime[j]<MAXN;j++){
      flag[i*prime[j]]=1;
      if(i%prime[j]==0)break;
    }
  }
}
int main(){
  int n,c,i,j;
  sieve();
  prime[0]=1;
  while(~scanf("%d%d",&n,&c)){
    printf("%d %d:",n,c);
    for(i=1;prime[i]<=n;i++);
    if(c*2>=i){
      for(j=0;j<i;j++)printf(" %d",prime[j]);
      puts("\n");
      continue;
    }
    if(i%2){
      for(j=(i+1)/2-c;j!=i/2+c;j++)printf(" %d",prime[j]);
    }else{
      for(j=i/2-c;j!=i/2+c;j++)printf(" %d",prime[j]);
    }
    puts("\n");
  }
}
