/*************************************************************************
     File Name: POJ2955.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月10日 星期五 15时35分17秒
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
const int N=110;
using namespace std;
char s[N];
int dp[N][N];

int check(int lhs,int rhs){
  if(s[lhs]=='('&&s[rhs]==')')return 1;
  if(s[lhs]=='['&&s[rhs]==']')return 1;
  return 0;
}

int main(){
  int i,j,k,len;
  while(~scanf("%s",s)&&s[0]!='e'){
    //cout<<s<<endl;
    len=strlen(s);
    Mem0(dp);
    //for(i=1;i<=len;++i)
      //dp[i][i]=0,dp[i][i+1]=check(i-1,i);
    for(i=len-1;i;--i)
      for(j=i+1;j<=len;++j){
        dp[i][j]=dp[i+1][j-1]+check(i-1,j-1);
        for(k=i;k<j;++k){
          dp[i][j]=Max(dp[i][j],dp[i][k]+dp[k+1][j]);
          //cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
        }
      }
    printf("%d\n",dp[1][len]*2);
  }
}
