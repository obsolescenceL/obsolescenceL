/*************************************************************************
     File Name: POJ2019.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月24日 星期五 12时32分04秒
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
#include<vector>
#include<set>
#include<bitset>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=300,M=10;
int num[N][N],minn[M][N][N],maxn[M][N][N],tlog[N],pw[M+1];

void RMQ_ST2(int n){
  int i,j,k;
  for(k=0;pw[k]<=n;++k)
    for(i=1;i<=n;++i)
      for(j=1;j<=n;++j){
        minn[k][i][j]=num[i][j];
        maxn[k][i][j]=num[i][j];
      }
  for(k=1;pw[k]<=n;++k)
    for(i=1;i<=n;++i)
      for(j=1;j<=n;++j){
        minn[k][i][j]=minn[k-1][i][j];
        maxn[k][i][j]=maxn[k-1][i][j];
        int ti=i+pw[k-1],tj=j+pw[k-1];
        if(ti<=n){
          minn[k][i][j]=Min(minn[k][i][j],minn[k-1][ti][j]);
          maxn[k][i][j]=Max(maxn[k][i][j],maxn[k-1][ti][j]);
        }
        if(tj<=n){
          minn[k][i][j]=Min(minn[k][i][j],minn[k-1][i][tj]);
          maxn[k][i][j]=Max(maxn[k][i][j],maxn[k-1][i][tj]);
        }
        if(ti<=n && tj<=n){
          minn[k][i][j]=Min(minn[k][i][j],minn[k-1][ti][tj]);
          maxn[k][i][j]=Max(maxn[k][i][j],maxn[k-1][ti][tj]);
        }
      }
}

int query(int x,int y,int b){
  int i,j,k=tlog[b],ans1=minn[0][x][y],ans2=maxn[0][x][y];
  for(i=x;i<x+b;i+=pw[k]){
    if(i+pw[k]>x+b-1)i=x+b-pw[k];
    for(j=y;j<y+b;j+=pw[k]){
      if(j+pw[k]>y+b-1)j=y+b-pw[k];
      ans1=Min(ans1,minn[k][i][j]);
      ans2=Max(ans2,maxn[k][i][j]);
    }
  }
  return ans2-ans1;
}

void init(){
  int i;
  for(i=0;i<=M;++i)pw[i]=1<<i;
  tlog[0]=-1;
  for(i=1;i<N;++i)tlog[i]=(i&(i-1))? tlog[i-1]:tlog[i-1]+1;
}

int main(){
  init();
  int i,j,n,b,q,x,y;
  while(~scanf("%d%d%d",&n,&b,&q)){
    for(i=1;i<=n;++i)
      for(j=1;j<=n;++j)
        scanf("%d",&num[i][j]);
    RMQ_ST2(n);
    while(q--){
      scanf("%d%d",&x,&y);
      printf("%d\n",query(x,y,b));
    }
  }
}
