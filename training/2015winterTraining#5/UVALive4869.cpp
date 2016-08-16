/*************************************************************************
     File Name: G.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月20日 星期三 12时15分34秒
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
const int N=250010,INF=0x3f3f3f3f;

int main(){
  int n,i,j,x;
  while(~scanf("%d",&n)&&n){
    bool flag=1;
    int sum=0,ans=0,maxn=-INF;
    for(i=1;i<=n;++i){
      scanf("%d",&x);
      if(x>0)flag=0;
      else maxn=Max(maxn,x);
      sum+=x;
      if(sum<0)sum=0;
      else ans=Max(ans,sum);
    }
    if(flag)printf("%d\n",maxn);
    else printf("%d\n",ans);
  }
}
