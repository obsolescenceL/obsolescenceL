/*************************************************************************
     File Name: G.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日 11/ 1 10:54:41 2015
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
const int N=15;
ll dp[N][N],l[N],r[N];
int path[N][N];

void Print(int i,int j){
  if(i==j) printf("A%d",i);
  else{
    printf("(");
    Print(i,path[i][j]);
    printf(" x ");
    Print(path[i][j]+1,j);
    printf(")");
  }
}

int main(){
  int n,i,j,k,nc=0;
  while(~scanf("%d",&n)&&n){
    for(i=1;i<=n;++i)scanf("%lld%lld",l+i,r+i);
    l[n+1]=r[n];
    MemX(dp),Mem0(path);
    for(i=1;i<=n;++i)dp[i][i]=0;
    for(i=n-1;i;--i)
      for(j=i+1;j<=n;++j)
        for(k=i;k<j;++k){
          int tmp=dp[i][k]+dp[k+1][j]+l[i]*l[k+1]*l[j+1];
          if(dp[i][j]>tmp){
            dp[i][j]=tmp;
            path[i][j]=k;
            //cout<<"k="<<k<<endl;
            //cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
          }
        }
    printf("Case %d: ",++nc);
    Print(1,n);
    puts("");
    //printf("%lld\n",dp[1][n]);
  }
}
