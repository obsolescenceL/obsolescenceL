/*************************************************************************
     File Name: HDU2888.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月25日 星期六 10时06分38秒
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
const int N=305,M=10;
int num[N][N],maxn[M][N][N],tlog[N],pw[M+1];

void RMQ_ST2(int n,int m){
  int i,j,k,nn=Max(n,m);
  for(k=0;pw[k]<=nn;++k)
    for(i=1;i<=n;++i)
      for(j=1;j<=m;++j)
        maxn[k][i][j]=num[i][j];
  for(k=1;pw[k]<=nn;++k)
    for(i=1;i<=n;++i)
      for(j=1;j<=m;++j){
        maxn[k][i][j]=maxn[k-1][i][j];
        int ti=i+pw[k-1],tj=j+pw[k-1];
        if(ti<=n)maxn[k][i][j]=Max(maxn[k][i][j],maxn[k-1][ti][j]);
        if(tj<=m)maxn[k][i][j]=Max(maxn[k][i][j],maxn[k-1][i][tj]);
        if(ti<=n && tj<=m)maxn[k][i][j]=Max(maxn[k][i][j],maxn[k-1][ti][tj]);
      }
}

int query(int x1,int y1,int x2,int y2){
  int i=tlog[x2-x1+1],j=tlog[y2-y1+1];
  int k=Min(i,j),ans=maxn[0][x1][y1];
  for(i=x1;i<=x2;i+=pw[k]){
    if(i+pw[k]>x2)i=x2-pw[k]+1;
    for(j=y1;j<=y2;j+=pw[k]){
      if(j+pw[k]>y2)j=y2-pw[k]+1;
      ans=Max(ans,maxn[k][i][j]);
    }
  }
  return ans;
}

void init(){
  int i;
  for(i=0;i<=M;++i)pw[i]=1<<i;
  tlog[0]=-1;
  for(i=1;i<=N;++i)
    tlog[i]=(i&(i-1))? tlog[i-1]:tlog[i-1]+1;
}

int main(){
  init();
  int i,j,n,m,q,x1,x2,y1,y2,ans;
  while(~scanf("%d%d",&n,&m)){
    for(i=1;i<=n;++i)
      for(j=1;j<=m;++j)
        scanf("%d",&num[i][j]);
    RMQ_ST2(n,m);
    scanf("%d",&q);
    while(q--){
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      ans=query(x1,y1,x2,y2);
      printf("%d ",ans);
      if(ans==num[x1][y1] || ans==num[x1][y2] || ans==num[x2][y1] || ans==num[x2][y2])puts("yes");
      else puts("no");
    }
  }
}
