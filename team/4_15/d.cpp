/*************************************************************************
     File Name: d.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月25日 星期六 22时50分22秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<cmath>
int card[20];

int main(){
  int i,j,k,n,m,ans,cnt;
  while(~scanf("%d",&n)){
    for(i=0;i<n;++i)
      scanf("%d",card+i);
    cnt=1;
    for(i=1;i<(1<<n);++i){
      m=ans=0;
      for(j=i,k=0;j;j>>=1,++k)
        if(j&1){
          ans^=card[k];
          m++;
        }
      if(!ans) cnt+=1<<m;
    }
    ans=((int)pow(3,n)+cnt)>>1;
    printf("%d\n",ans);
  }
}
