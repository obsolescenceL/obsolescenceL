/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月27日 星期三 12时02分33秒
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
int a[N],dp[N][N];

int main(){
  int t,n,m,i,j;
  while(~scanf("%d",&t)){
    for(int nc=1;nc<=t;++nc){
      scanf("%d%d",&n,&m);
      for(i=0;i<n;++i){
        scanf("%d",a+i);
      }
      sort(a,a+n,greater<int>());
      MemX(dp);
      dp[0][0]=a[0]-a[n-1];
      for(i=1;i<n;++i){
        dp[i][0]=dp[i-1][0];
        for(j=1;j<m;++j){
          dp[i][j]=Min(dp[i-1][j],dp[i-1][j-1]-(a[i-1]-a[i]));
          //cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
        }
      }
      printf("Case #%d: %d\n",nc,dp[n-1][m-1]);
    }
  }
}
