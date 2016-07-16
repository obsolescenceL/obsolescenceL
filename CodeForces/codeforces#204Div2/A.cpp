/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月16日 星期六 08时59分02秒
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
  int n,i,cnt0,cnt5,x;
  while(~scanf("%d",&n)){
    cnt0=cnt5=0;
    for(i=0;i<n;++i){
      scanf("%d",&x);
      if(x)cnt5++;
      else cnt0++;
    }
    while(cnt5){
      if(cnt5*5%9==0)break;
      cnt5--;
    }
    if(!cnt0)puts("-1");
    else if(!cnt5)puts("0");
    else{
      while(cnt5--)printf("5");
      while(cnt0--)printf("0");
      puts("");
    }
  }
}
