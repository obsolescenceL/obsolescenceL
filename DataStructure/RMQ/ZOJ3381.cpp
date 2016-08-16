/*************************************************************************
     File Name: ZOJ3381.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月24日 星期五 11时06分25秒
 ************************************************************************/
#include<cstdio>
#include<cmath>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
const int N=50010,M=20;
int n,num[N],x[N],y[N],maxn[N][M],dp[N];

void update(int x){
  maxn[x][0]=dp[x];
  for(int i=1;x<=n-(1<<i)+1;++i)
    maxn[x][i]=Max(maxn[x][i-1],maxn[x+(1<<(i-1))][i-1]);
}

int query(int l,int r){
  if(l>r)return 0;
  int k=(int)(log(r-l+1.0)/log(2.0));
  return Max(maxn[l][k],maxn[r-(1<<k)+1][k]);
}

int main(){
  int i,j;
  while(~scanf("%d",&n)){
    for(i=1;i<=n;++i){
      scanf("%d%d%d",num+i,x+i,y+i);
      x[i]+=i;
      y[i]=Min(n,y[i]+i-1);
    }
    for(i=n;i>0;--i){
      dp[i]=num[i]+query(x[i],y[i]);
      update(i);
    }
    printf("%d\n",dp[1]);
  }
}
