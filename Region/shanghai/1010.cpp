/*************************************************************************
     File Name: 1010.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年09月26日 星期六 12时33分26秒
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

int main(){
  int t,n,a,b,L,l,r,maxn,s;
  while(~scanf("%d",&t)){
    for(int nc=1;nc<=t;++nc){
      scanf("%d%d%d%d",&n,&a,&b,&L);
      maxn=s=l=r=0;
      while(n--){
        //cout<<"s="<<s<<endl;
        scanf("%d",&l);
        s+=b*(l-r);
        scanf("%d",&r);
        s-=a*(r-l);
        //cout<<"s="<<s<<endl;
        maxn=Min(maxn,s);
      }
      printf("Case #%d: %d\n",nc,-maxn);
    }
  }
}
