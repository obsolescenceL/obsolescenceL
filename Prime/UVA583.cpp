/*************************************************************************
    > File Name: D.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 4日 10:50:43
 ************************************************************************/
#include<cstdio>
#include<cmath>
const int MAXN=46340;
bool sieve[MAXN];
int p[MAXN/3],k;
void prime(){
  for(int i=2;i<MAXN;i++){
    if(!sieve[i])p[k++]=i;
    for(int j=0;i*p[j]<MAXN;j++){
      sieve[i*p[j]]=1;
      if(i%p[j]==0)break;
    }
  }
  //for(int i=0;i<30;i++)printf("p[%d]=%d ",i,p[i]);
}
int main(){
  long long g,i;
  prime();
  while(~scanf("%lld",&g)&&g){
    printf("%lld = ",g);
    int f=0;
    if(g<0)f=1,g=-g,printf("-1");
    for(i=0;sqrt(1.0*g)>=p[i]&&i<k;){
      if(g%p[i])i++;
      else if(f)g/=p[i],printf(" x %d",p[i]);
      else g/=p[i],printf("%d",p[i]),f=1;
    }
    if(g>1){
      if(f)printf(" x %lld",g);
      else printf("%lld",g);
    }
    puts("");
  }
}
