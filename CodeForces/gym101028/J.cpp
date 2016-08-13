/*************************************************************************
     File Name: J.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月12日 星期二 15时18分58秒
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
const int N=110;
int a[N],b[N],dp[N];

int main(){
  int t,n,i,j,x;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&n);
      for(i=0;i<n;++i){
        scanf("%d",a+i);
        b[i]=0;
        x=a[i];
        while(x%2==0)x>>=1,b[i]++;
        //cout<<"b["<<i<<"]="<<b[i]<<endl;
        dp[i]=b[i];
      }
      for(i=1;i<n;++i)
        for(j=0;j<i;++j)
          if(a[i]>a[j])
            dp[i]=Max(dp[i],dp[j]+b[i]);
      int ans=0;
      for(i=0;i<n;++i)
        ans=Max(ans,dp[i]);
      printf("%d\n",ans);
    }
  }
}
