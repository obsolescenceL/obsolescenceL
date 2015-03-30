/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月28日 星期六 14时00分12秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;
int mp[110][110],sum[110][110];
int n,m;

int max1(int *a){
  int ans=0,summ=0;
  for(int i=0;i<m;++i){
    if(summ>=0)summ+=a[i];
    else summ=a[i];
    ans=max(ans,summ);
  }
  return ans;
}

int max2(int a[][110]){
  int ans=0,summ[110];
  for(int i=0;i<n;++i){
    memset(summ,0,sizeof summ);
    for(int j=i;j<n;++j){
      for(int k=0;k<m;++k)
        summ[k]+=a[j][k];
      ans=max(ans,max1(summ));
      //cout<<"ans="<<ans<<endl;
    }
  }
  return ans;
}

int main(){
  int i,j;
  while(~scanf("%d%d",&n,&m)){
    memset(sum,0,sizeof sum);
    for(i=0;i<n;++i){
      for(j=0;j<m;++j){
        scanf("%d",&mp[i][j]);
        if(j)sum[i][j]=mp[i][j]-mp[i][j-1];
      }
    }
    /*
    int max_sum=0;
    for(j=0;j<m;++j){
      int summ=0;
      for(i=0;i<n;++i){
        if(sum[i][j]>=0)summ+=sum[i][j];
        else summ=sum[i][j];
      }
      max_sum=max(max_sum,summ);
    }
    */
    printf("%d\n",max2(sum));
    /*
    for(i=0;i<n;++i)
      for(j=0;j<m;++j)
        printf("sum[%d][%d]=%d\n",i,j,sum[i][j]);
        */
  }
}
