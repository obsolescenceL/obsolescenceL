/*************************************************************************
     File Name: c.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月23日 星期四 12时06分04秒
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
const int N=10010;
struct cube{
  ll a,b,c;
}cu[N],max_cu;

int main(){
  ll i,n,sum;
  while(~scanf("%I64d",&n)){
    scanf("%I64d%I64d%I64d",&cu[0].a,&cu[0].b,&cu[0].c);
    max_cu.a=cu[0].a;
    max_cu.b=cu[0].b;
    max_cu.c=cu[0].c;
    sum=max_cu.a*max_cu.b*max_cu.c;
    for(i=1;i<n;++i){
      scanf("%I64d%I64d%I64d",&cu[i].a,&cu[i].b,&cu[i].c);

      if(cu[i].a>=max_cu.a && cu[i].b>=max_cu.b && cu[i].c>=max_cu.c){
        max_cu.a=cu[i].a;
        max_cu.b=cu[i].b;
        max_cu.c=cu[i].c;
      }
      sum=max_cu.a*max_cu.b*max_cu.c;
    }
    for(i=0;i<n;++i){
      if(cu[i].a>max_cu.a)
        sum+=(cu[i].a-max_cu.a)*cu[i].b*cu[i].c;
      if(cu[i].b>max_cu.b)
        sum+=(cu[i].b-max_cu.b)*cu[i].a*cu[i].c;
      if(cu[i].c>max_cu.c)
        sum+=(cu[i].c-max_cu.c)*cu[i].b*cu[i].a;
    }
    printf("%I64d\n",sum);
  }
}
