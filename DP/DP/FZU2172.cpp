/*************************************************************************
     File Name: FZU2172.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 二  5/ 3 23:07:25 2016
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
const int N=20;
int dp[N][N];
char a[N],b[N];

int main(){
  int i,j,k,n,m;
  while(~scanf("%s%s",a,b)){
    n=strlen(a),m=strlen(b);
    MemX(dp);
    for(i=0;i<=m;++i)dp[0][i]=i;
    for(i=1;i<=n;++i)dp[i][0]=i;
    for(i=0;i<=n;++i)
    //for(i=n;i>=1;--i)
      for(j=0;j<=m;++j){
      //for(j=m;j>=1;--j){
        //dp[i][j]=Min(dp[i-1][j]+1,dp[i][j-1]+1);
        if(i+1<=n)dp[i+1][j]=Min(dp[i+1][j],dp[i][j]+1);
        if(j+1<=m)dp[i][j+1]=Min(dp[i][j+1],dp[i][j]+1);
        if(a[i]==b[j])dp[i+1][j+1]=Min(dp[i+1][j+1],dp[i][j]);
        else dp[i+1][j+1]=Min(dp[i+1][j+1],dp[i][j]+2);
        //cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
        //if(j&1)continue;
        if(2*j>m)continue;
        bool flag=1;
        for(k=0;k<j;++k)
          if(b[k]!=b[k+j]){
            flag=0;break;
          }
        //cout<<"flag="<<flag<<endl;
        if(flag)dp[i][j*2]=Min(dp[i][j*2],dp[i][j]+1);
        //cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
        //cout<<"------------"<<endl;
      }
    if(dp[n][m]<=15)printf("%d\n",dp[n][m]);
    else puts("more than 15 operations.");
  }
}
