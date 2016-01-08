/*************************************************************************
     File Name: C_2.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 二  1/ 5 21:42:43 2016
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
const int N=1e5+10;
int a[N],dp1[N],dp2[N],v[N],ans[N],c[N];

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    for(i=1;i<=n;++i)scanf("%d",a+i);
    MemX(v);
    int max_len=0,pos;
    for(i=1;i<=n;++i){
      pos=lower_bound(v,v+max_len,a[i])-v;
      dp1[i]=pos+1;
      v[pos]=a[i];
      max_len=Max(max_len,dp1[i]);
    }
    for(i=n;i>=1;--i){
      pos=lower_bound(v,v+max_len,-a[i])-v;
      dp2[i]=pos+1;
      v[pos]=-a[i];
    }
    Mem0(c);
    for(i=1;i<=n;++i)
      if(dp1[i]+dp2[i]!=max_len+1)
        ans[i]=1;
      else ans[i]=0,c[dp1[i]]++;
    for(i=1;i<=n;++i){
      if(!ans[i])ans[i]=c[dp1[i]]>1? 2:3;
      printf("%d",ans[i]);
    }
    puts("");
  }
}
