/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月13日 星期三 13时25分22秒
 ************************************************************************/
#include<bits/stdc++.h>
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
int a[N];

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    scanf("%d",a);
    int g=a[0];
    for(i=1;i<n;++i){
      scanf("%d",a+i);
      g=__gcd(g,a[i]);
    }
    sort(a,a+n);
    if((a[n-1]/g-n)%2)puts("Alice");
    else puts("Bob");
  }
}

