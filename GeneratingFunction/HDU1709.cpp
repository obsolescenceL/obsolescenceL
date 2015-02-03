/*************************************************************************
    > File Name: HDU1709.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 6日 16:47:21
 ************************************************************************/
#include<cstdio>
const int MAXN=10010;
int c1[MAXN],c2[MAXN],num[110],unfind[MAXN];
int main(){
  int n,i,j,k;
  while(~scanf("%d",&n)){
    int sum=0,cnt=0;
    for(i=1;i<=n;i++)scanf("%d",num+i),sum+=num[i];
    for(i=0;i<=sum;i++)c1[i]=c2[i]=0;
    c1[0]=c1[num[1]]=1;
    for(i=2;i<=n;i++){
      for(j=0;j<=sum;j++){
        for(k=0;j+k<=sum && k<=num[i];k+=num[i]){
          if(j>=k)c2[j-k]+=c1[j];
          else c2[k-j]+=c1[j];
          c2[k+j]+=c1[j];
        }
      }
      for(j=0;j<=sum;j++)
        c1[j]=c2[j],c2[j]=0;
    }
    for(i=1,j=0;i<=sum;i++)
      if(!c1[i]) cnt++,unfind[j++]=i;
    printf("%d\n",cnt);
    if(cnt){
      for(i=0;i<cnt;i++){
        if(i)printf(" %d",unfind[i]);
        else printf("%d",unfind[i]);
      }
      puts("");
    }
  }
}
