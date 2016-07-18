/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月18日 星期一 10时49分53秒
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

int main(){
  int n,i,sum,sx,x,y;
  while(~scanf("%d",&n)){
    bool flag=0;
    sum=sx=0;
    for(i=0;i<n;++i){
      scanf("%d%d",&x,&y);
      sum+=x+y;
      sx+=x;
      if((x+y)%2)flag=1;
    }
    if(sum%2)puts("-1");
    else if(sx%2==0)puts("0");
    else if(flag)puts("1");
    else puts("-1");
  }
}
