/*************************************************************************
    > File Name: HDU1028.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 6日 10:54:56
 ************************************************************************/
#include<cstdio>
const int MAXN=121;
int c1[MAXN],c2[MAXN];
int main(){
  int n,i,j,k;
  while(~scanf("%d",&n)){
    for(i=0;i<=n;i++)c1[i]=1,c2[i]=0;
    for(i=2;i<=n;i++){
      for(j=0;j<=n;j++){
        for(k=0;k+j<=n;k+=i)
          c2[k+j]+=c1[j];
        c1[j]=c2[j],c2[j]=0;
      }
    }
    printf("%d\n",c1[n]);
  }
}
