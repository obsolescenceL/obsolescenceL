/*************************************************************************
     File Name: ZOJ2859.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月19日 星期日 9时38分38秒
 ************************************************************************/
#include<cstdio>
#define Min(x,y) ((x)<(y)?(x):(y))
const int N=305,M=10;

int num[N][N],minn[M][N][N],tlog[N],pw[M+1];

void RMQ_ST2(int n){
  int i,j,k;
  for(k=0;pw[k]<=n;++k)
    for(i=1;i<=n;++i)
      for(j=1;j<=n;++j)minn[k][i][j]=num[i][j];
  for(k=1;pw[k]<=n;++k)
    for(i=1;i<=n;++i)
      for(j=1;j<=n;++j){
        minn[k][i][j]=minn[k-1][i][j];
        if(i+pw[k-1]<=n)
          minn[k][i][j]=Min(minn[k][i][j],minn[k-1][i+pw[k-1]][j]);
        if(j+pw[k-1]<=n)
          minn[k][i][j]=Min(minn[k][i][j],minn[k-1][i][j+pw[k-1]]);
        if(i+pw[k-1]<=n && j+pw[k-1]<=n)
          minn[k][i][j]=Min(minn[k][i][j],minn[k-1][i+pw[k-1]][j+pw[k-1]]);
      }
}

int query(int x1,int y1,int x2,int y2){
  int i=tlog[x2-x1+1];
  int j=tlog[y2-y1+1];
  int k=Min(i,j),ans=minn[0][x1][y1];
  for(i=x1;i<=x2;i+=pw[k]){
    if(i+pw[k]>x2)i=x2-pw[k]+1;
    for(j=y1;j<=y2;j+=pw[k]){
      if(j+pw[k]>y2)j=y2-pw[k]+1;
      ans=Min(ans,minn[k][i][j]);
    }
  }
  return ans;
}

void init(){
  int i;
  for(i=0;i<=M;++i)pw[i]=1<<i;
  tlog[0]=-1;
  for(i=1;i<N;++i)
    tlog[i]=(i&(i-1))? tlog[i-1]:tlog[i-1]+1;
}


int main(){
  init();
  int i,j,t,n,q,x1,x2,y1,y2;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&n);
      for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
          scanf("%d",&num[i][j]);
      RMQ_ST2(n);
      scanf("%d",&q);
      while(q--){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",query(x1,y1,x2,y2));
      }
    }
  }
}
