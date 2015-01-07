/*************************************************************************
    > File Name: HDU2152.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 7日  9:17:07
 ************************************************************************/
#include<cstring>
#include<cstdio>
const int MAXN=10010;
int c1[MAXN],c2[MAXN],a[110],b[110],n,m;
int main(){
  int i,j,k;
  while(~scanf("%d%d",&n,&m)){
    memset(c1,0,sizeof(c1));
    memset(c2,0,sizeof(c2));
    for(i=1;i<=n;i++)scanf("%d%d",a+i,b+i);
    for(i=a[1];i<=b[1];i++)c1[i]=1;
    for(i=2;i<=n;i++){
      for(j=0;j<=m;j++){
        for(k=a[i];j+k<=m && k<=b[i];k++)
          c2[j+k]+=c1[j];
      }
      for(j=0;j<=m;j++)
        c1[j]=c2[j],c2[j]=0;
    }
    printf("%d\n",c1[m]);
  }
}
