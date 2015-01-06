/*************************************************************************
    > File Name: HDU1171.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 6日 21:11:11
 ************************************************************************/
#include<cstdio>
#include<cstring>
const int MAXN=130000;
int c1[MAXN],c2[MAXN];
int v[55],m[55];
int main(){
  int n,i,j,k;
  while(scanf("%d",&n),n>=0){
    if(n==0) continue;
    int sum=0;
    for(i=1;i<=n;i++){
      scanf("%d%d",v+i,m+i);
      sum+=v[i]*m[i];
    }
    memset(c1,0,sizeof(c1));
    memset(c2,0,sizeof(c2));
    for(i=0;i<=m[1]*v[1];i+=v[1])c1[i]=1;
    for(i=2;i<=n;i++){
      for(j=0;j<=sum/2;j++){
        if(!c1[j])continue;
        for(k=0;j+k*v[i]<=sum/2&&k<=m[i];k++)
            c2[j+k*v[i]]+=c1[j];
      }
       for(j=0;j<=sum/2;j++)c1[j]=c2[j],c2[j]=0;
    }
    for(i=sum/2;i>=0;i--) if(c1[i]) break;
    printf("%d %d\n",sum-i,i);
  }
}
