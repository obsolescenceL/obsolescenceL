/*************************************************************************
    > File Name: HDU1085.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 6日 13:14:00
 ************************************************************************/
#include<cstdio>
const int MAXN=8010;
int c1[MAXN],c2[MAXN];
int coins[4]={0,1,2,5},n[4];
int main(){
  int a,b,c,x;
  while(~scanf("%d%d%d",&n[1],&n[2],&n[3])&&(n[1]||n[2]||n[3])){
    int i,j,k;
    for(i=0;i<=MAXN;i++)c1[i]=0,c2[i]=0;
    c1[0]=1;
    int maxn=0;
    for(i=1;i<=3;i++){
      maxn+=coins[i]*n[i];
      for(j=0;j<=maxn;j++){
        for(k=0;k<=n[i]&&j+k*coins[i]<=maxn;k++)
          c2[j+k*coins[i]]+=c1[j];
        c1[j]=c2[j],c2[j]=0;
      }
    }
    for(i=1;;i++)
      if(!c1[i]){
        printf("%d\n",i);
        break;
      }
  }
}
