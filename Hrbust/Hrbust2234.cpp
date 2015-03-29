/*************************************************************************
     File Name: c.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月28日 星期六 13时21分44秒
 ************************************************************************/
#include<cstdio>
int num[100];

int main(){
  int t,p,q,i;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d",&p,&q);
      if(p==1||q==1){
        printf("%d\n",q);
        continue;
      }
      num[0]=1;
      num[1]=p;
      for(i=2;num[i-1]<=q;++i){
        num[i]=num[i-1]*p;
      }
      i-=2;
      int cnt=1;
      q-=num[i];
      while(q){
        for(;num[i]>q;--i);
        while(q>=num[i]){
          q-=num[i];
          cnt++;
        }
      }
      printf("%d\n",cnt);
    }
  }
}
