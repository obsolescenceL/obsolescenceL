/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月23日 22:09:51
 ************************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<iostream>
#include<cctype>
#include<climits>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int INF=0x3F3F3F3F;
struct node{
  int va,vo;
  bool operator < (const node& rhs)const{
    return va>rhs.va || (va==rhs.va&&vo<rhs.vo);
  }
}bone[1010];
int dp[1010];

int main(){
  int t,n,v,i,j,ans;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d",&n,&v);
      for(i=1;i<=n;++i)scanf("%d",&bone[i].va);
      for(i=1;i<=n;++i)scanf("%d",&bone[i].vo);
      memset(dp,0,sizeof dp);
      ans=0;
      for(i=1;i<=n;++i){
        for(j=v;j>=bone[i].vo;--j){
          dp[j]=Max(dp[j-bone[i].vo]+bone[i].va,dp[j]);
          ans=Max(ans,dp[j]);
        }
      }
      printf("%d\n",ans);
    }
  }
}
