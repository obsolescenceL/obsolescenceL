/*************************************************************************
     File Name: e7.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月23日 星期一 17时03分28秒
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
using namespace std;
const int N=21;
const long long INF=1LL<<31;
long long old_sum;
long long a[N][N][N];
int A,B,C;
bool flag;

inline long long max1(long long *b){
  long long ans=-INF,sum=0;
  for(int i=0;i<C;++i){
    if(sum>0)sum+=b[i];
    else sum=b[i];
    ans=max(ans,sum);
    //cout<<"1   "<<ans<<endl;
  }
  return ans;
}

inline long long max2(long long b[][N]){
  long long ans=-INF,sum[N];
  for(int i=0;i<B;++i){
    memset(sum,0,sizeof sum);
    for(int j=i;j<B;++j){
      for(int k=0;k<C;++k)
        sum[k]+=b[j][k];
      ans=max(ans,max1(sum));
      //cout<<"2  "<<ans<<endl;
    }
  }
  return ans;
}

inline long long max3(long long b[][N][N]){
  long long ans=-INF,sum[N][N],maxn;
  for(int i=0;i<A;++i){
    memset(sum,0,sizeof sum);
    for(int j=i;j<A;++j){
      for(int k=0;k<B;++k)
        for(int l=0;l<C;++l)
          sum[k][l]+=b[j][k][l];
      maxn=max2(sum);
      if(maxn>ans/*&&maxn!=old_sum*/)
        ans=maxn;
      //cout<<"3 "<<ans<<endl;
    }
  }
  return ans;
}

int main(){
  int t,i,j,k;
  long long maxn;
  while(~scanf("%d",&t)){
    //cout<<t<<endl;
    while(t--){
      old_sum=0;
      memset(a,0,sizeof a);
      scanf("%d%d%d",&A,&B,&C);
      //cout<<A<<' '<<B<<' '<<C<<endl;
      for(i=0;i<A;++i)
        for(j=0;j<B;++j)
          for(k=0;k<C;++k){
            scanf("%lld",&a[i][j][k]);
            old_sum+=a[i][j][k];
            //printf("%d",a[i][j][k]);
          }
      maxn=max3(a);
      //if(maxn==old_sum)
      printf("%lld\n",maxn);
      //long long ans=INF;
      //printf("%lld\n",ans);
      if(t)puts("");
    }
  }
}
