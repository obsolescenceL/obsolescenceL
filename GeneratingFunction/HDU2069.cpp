/*************************************************************************
    > File Name: HDU2069.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 7日 10:27:42
 ************************************************************************/
#include<cstdio>
#include<cstring>
const int MAXN=260;
int c1[MAXN][110],c2[MAXN][110],coins[]={0,1,5,10,25,50},n,i,j,k,l;
int main(){
  while(~scanf("%d",&n)){
    memset(c1,0,sizeof(c1));
    memset(c2,0,sizeof(c2));
    for(i=0;i<=n&&i<=100;i++)c1[i][i]=1;
    for(i=2;i<=5;i++)
      for(j=0;j<=n;j++){
        for(k=0;j+k*coins[i]<=n;k++)
          for(l=0;l+k<=100;l++)
            c2[j+k*coins[i]][l+k]+=c1[j][l];
        for(l=0;l<=100;l++)
          c1[j][l]=c2[j][l],c2[j][l]=0;
      }
    int sum=0;
    for(i=0;i<=100;i++)sum+=c1[n][i];
    printf("%d\n",sum);
  }
}
