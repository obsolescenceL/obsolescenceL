/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六 10/30 20:32:35 2015
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
const int N=1010,INF=0x3f3f3f3f;
int dp[N][N],c[55];

int main(){
  int l,n,i,j,k;
  while(~scanf("%d",&l)&&l){
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",c+i);
    sort(c+1,c+n+1);
    c[n+1]=l;
    for(i=0;i<=n+1;++i)
      for(j=0;j<=n+1;++j)
        dp[c[i]][c[j]]=INF;
    for(i=0;i<=n;++i)
      dp[c[i]][c[i+1]]=0;
    for(j=1;j<=n+1;++j){
      for(i=0;i<=n && i+j<=n+1;++i){
        for(k=i;k<i+j;++k){
          //cout<<"dp["<<c[i]<<"]["<<c[i+j]<<"]="<<dp[c[i]][c[i+j]]<<endl;
          dp[c[i]][c[i+j]]=Min(dp[c[i]][c[k]]+dp[c[k]][c[i+j]]+c[i+j]-c[i],dp[c[i]][c[i+j]]);
          //cout<<"c["<<i<<"]="<<c[i]<<"   c["<<i+j<<"]="<<c[i+j]<<endl;
          //cout<<"dp["<<c[i]<<"]["<<c[i+j]<<"]="<<dp[c[i]][c[i+j]]<<endl;
        }
      }
    }
    printf("The minimum cutting is %d.\n",dp[0][l]);
  }
}
