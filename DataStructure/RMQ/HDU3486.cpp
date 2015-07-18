/*************************************************************************
     File Name: HDU3486.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月18日 星期六 16时06分10秒
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
const int N=200010,M=20,INF=0x3f3f3f3f;
int maxn[N][M],num[N];

void RMQ_ST(int n){
  int i,j;
  for(i=1;i<=n;++i)
    maxn[i][0]=num[i];
  for(j=1;j<M;++j)
    for(i=1;i<=n-(1<<j)+1;++i)
      maxn[i][j]=Max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);
}

int main(){
  int i,j,n,m,ans;
  while(~scanf("%d%d",&n,&m)&&(n>=0||m>=0)){
    int sum=0,max_n=0,min_n=INF;
    for(i=1;i<=n;++i){
      scanf("%d",num+i);
      sum+=num[i];
      max_n=Max(max_n,num[i]);
      min_n=Min(min_n,num[i]);
    }
    if(sum<m){
      puts("-1");continue;
    }
    if(max_n>=m){
      puts("1");continue;
    }
    RMQ_ST(n);
    if(!max_n)max_n=1;
    if(!min_n)min_n=1;
    int low=Max(m/max_n,1),high=Min(m/min_n+1,n),mid,temp,l,r;
    while(high>=low){//二分段数
      mid=(low+high)>>1;
      temp=0;
      int len=n/mid;
      for(i=1;i<=mid;++i){
        l=len*(i-1)+1,r=len*i;
        int k=(int)(log(r-l+1.0)/log(2.0));
        temp+=Max(maxn[l][k],maxn[r-(1<<k)+1][k]);
      }
      if(temp>m){
        high=mid-1;
        ans=mid;
      }else low=mid+1;
    }
    printf("%d\n",ans);
  }
}
