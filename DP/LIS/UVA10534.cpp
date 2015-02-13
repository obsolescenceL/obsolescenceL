/*************************************************************************
    > File Name: UVA10534.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 3日 21:59:35
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=10010;
int dp_lis[MAXN],dp_lds[MAXN],a[MAXN];
int main(){
  int n,i,j;
  while(~scanf("%d",&n)){
    for(i=0;i<n;i++){
      scanf("%d",a+i);
      dp_lis[i]=1;
      dp_lds[i]=1;
    }
    int max_lis=0,max_lds=0,v[MAXN],pos;
    for(i=0;i<n;i++){
      pos=lower_bound(v,v+max_lis,a[i])-v;
      dp_lis[i]=pos+1;
      v[pos]=a[i];
      max_lis=max(max_lis,pos+1);
    }
    for(i=n-1;i>=0;i--){
      pos=lower_bound(v,v+max_lds,a[i])-v;
      dp_lds[i]=pos+1;
      v[pos]=a[i];
      max_lds=max(max_lds,pos+1);
    }
    //for(i=0;i<n;i++) printf("dp_lis[%d]=%d,dp_lds[%d]=%d\n",i,dp_lis[i],i,dp_lds[i]);
    int ans=0;
    for(i=0;i<n;i++)ans=max(ans,min(dp_lis[i],dp_lds[i]));
    printf("%d\n",ans*2-1);
  }
}

