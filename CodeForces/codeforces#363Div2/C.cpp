/*************************************************************************
     File Name: C.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月19日 星期二 22时31分13秒
 ************************************************************************/
#include<bits/stdc++.h>
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
const int N=110;
int a[N],dp[N][5];

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    MemX(dp);
    dp[0][0]=0;
    for(i=1;i<=n;++i){
      scanf("%d",a+i);
      dp[i][0]=0;
    }
    for(i=1;i<=n;++i){
      //cout<<"a["<<i<<"]="<<a[i]<<endl;
      if(a[i]==3){
        dp[i][1]=Min(dp[i-1][2],dp[i-1][0]);
        dp[i][2]=Min(dp[i-1][1],dp[i-1][0]);
      }else if(a[i]==2){
        dp[i][2]=Min(dp[i-1][1],dp[i-1][0]);
      }else if(a[i]==1){
        dp[i][1]=Min(dp[i-1][2],dp[i-1][0]);
      }
      dp[i][0]=Min(dp[i-1][1]+1,Min(dp[i-1][2]+1,dp[i-1][0]+1));
      //cout<<"dp["<<i<<"][0]="<<dp[i][0]<<' ';
      //cout<<"dp["<<i<<"][1]="<<dp[i][1]<<' ';
      //cout<<"dp["<<i<<"][2]="<<dp[i][2]<<endl;
    }
    printf("%d\n",Min(dp[n][0],Min(dp[n][1],dp[n][2])));
  }
}
