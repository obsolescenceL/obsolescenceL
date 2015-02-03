/*************************************************************************
    > File Name: POJ3278.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 8日 21:44:03
 ************************************************************************/
#include<cstdio>
#include<cstring>
const int MAXN=200010;
int n,k,cnt[MAXN],q[MAXN];
int main(){
  while(~scanf("%d%d",&n,&k)){
    memset(cnt,-1,sizeof(cnt));
    if(n>=k)printf("%d\n",n-k);
    else{
      int f=0,r=1,nn;
      q[0]=n,cnt[n]=0;
      while(f!=r){
        n=q[f++];
        if(n==k)break;
        nn=n+1;
        if(nn<=2*k&&cnt[nn]==-1)cnt[nn]=cnt[n]+1,q[r++]=nn;
        nn=n-1;
        if(nn>=0&&cnt[nn]==-1)cnt[nn]=cnt[n]+1,q[r++]=nn;
        nn=n*2;
        if(nn<=2*k&&cnt[nn]==-1)cnt[nn]=cnt[n]+1,q[r++]=nn;
      }
      printf("%d\n",cnt[k]);
    }
  }
}
