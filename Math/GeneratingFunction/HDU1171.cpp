/*************************************************************************
    > File Name: HDU1171.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 6日 15:02:05
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
struct facility{
  int v,m;
}fac[55];
bool cmp(facility a,facility b){
  return a.v>b.v;
}
int main(){
  int sum,b,n,i,j,k;
  while(~scanf("%d",&n)&&n>=0){
    sum=b=0;
    for(i=0;i<n;i++){
      scanf("%d%d",&fac[i].v,&fac[i].m);
      sum+=fac[i].v*fac[i].m;
    }
    sort(fac,fac+n,cmp);
    for(i=0;i<n;i++){
      for(j=0;j<fac[i].m;j++){
        if(b>=sum/2)break;
        b+=fac[i].v;
      }
      if(b>sum/2)b-=fac[i].v;
      if(b==sum/2)break;
    }
    printf("%d %d\n",sum-b,b);
  }
}
