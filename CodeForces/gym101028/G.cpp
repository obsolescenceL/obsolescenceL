/*************************************************************************
     File Name: G.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月12日 星期二 14时21分10秒
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
  int t,n,m,p,a,b;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d%d",&n,&m,&p);
      if(n>m){
        n-=m;
        a=(n+m-2)/(m-1)+1;
        b=n%(m-1);
      }else a=1,b=n-1;
      if(m==2 && a!=1)a++;
      if(a%2){
        if(b+1==p)puts("Yes");
        else puts("No");
      }else{
        if(m-b==p)puts("Yes");
        else puts("No");
      }
    }
  }
}
