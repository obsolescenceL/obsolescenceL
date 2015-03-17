/*************************************************************************
    > File Name: A.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 3日 22:58:39
 ************************************************************************/
#include<cstdio>
int main(){
  int n,k;
  while(~scanf("%d",&n)){
    for(int x=1;x<=n;x++){
      scanf("%d",&k);
      int a[5],b[5],j=1;
      for(int i=2;j!=3;i++)
        if(k%i==0)a[j]=i,b[j]=k/i,j++;
      printf("Case #%d: %d = %d * %d = %d * %d\n",x,k,a[1],b[1],a[2],b[2]);
    }
  }
}
