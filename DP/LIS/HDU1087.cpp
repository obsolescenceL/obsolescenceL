/*************************************************************************
    > File Name: HDU1087.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 1日 13:22:27
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1010;
int s[MAXN],sum[MAXN];
int main(){
  int i,j,n,max_sum;
  while(~scanf("%d",&n)&&n){
    for(i=0;i<n;i++){
      scanf("%d",s+i);
      sum[i]=s[i];
    }
    max_sum=0;
    for(i=0;i<n;i++){
      for(j=0;j<i;j++)
        if(s[j]<s[i])sum[i]=max(sum[i],sum[j]+s[i]);
      max_sum=max(max_sum,sum[i]);
    }
    printf("%d\n",max_sum);
  }
}
