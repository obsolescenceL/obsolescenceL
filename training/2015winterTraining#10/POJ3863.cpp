/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年02月03日 星期三 11时54分31秒
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
const int INF=0x3f3f3f3f;

int main(){
  int n,m,i,j,u,d,x,ans;
  while(~scanf("%d%d",&n,&m)){
    ans=INF;
    for(i=1,j=0;i<=m;++i){
      scanf("%d%d",&u,&d);
      if(!n*d%(u+d))x=n*d/(u+d);
      else x=n*d/(u+d)+1;
      int tmp=x*u-(n-x)*d;
      if(!tmp)tmp=u+d;
      ans=Min(ans,tmp);
    }
    printf("%d\n",ans);
  }
}
