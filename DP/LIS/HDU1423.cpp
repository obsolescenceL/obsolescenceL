/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月21日 18:03:13
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
using namespace std;
const int M=510;
long long a[M],b[M];
int dp[M];

int main(){
  int t,n,m,i,j,mx_len;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&n);
      for(i=0;i<n;++i){
        scanf("%lld",a+i);
      }
      scanf("%d",&m);
      for(i=0;i<m;++i){
        scanf("%lld",b+i);
      }
      memset(dp,0,sizeof dp);
      for(i=1;i<=n;++i){
        mx_len=0;
        for(j=1;j<=m;++j){
          if(a[i-1]>b[j-1])mx_len=max(mx_len,dp[j]);
          if(a[i-1]==b[j-1])dp[j]=mx_len+1;
        }
      }
      for(i=1;i<=m;++i)
        mx_len=max(mx_len,dp[i]);
      printf("%d\n",mx_len);
      if(t)puts("");
    }
  }
}
