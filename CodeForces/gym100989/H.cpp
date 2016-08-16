/*************************************************************************
     File Name: H.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月18日 星期一 12时43分58秒
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
  int n,k,cnt1,cnt5,cnt10,cnt20,cnt50;
  int x1,x5,x10,x20,x50,charge;
  while(~scanf("%d",&n)){
    cnt1=cnt5=cnt10=cnt20=cnt50=0;
    bool flag=1;
    for(int i=0;i<n;++i){
      scanf("%d%d%d%d%d%d",&k,&x1,&x5,&x10,&x20,&x50);
      cnt1+=x1,cnt5+=x5,cnt10+=x10;
      cnt20+=x20,cnt50+=x50;
      charge=x1*1+x5*5+x10*10+x20*20+x50*50-k;
      while(charge>=50 && cnt50)
        charge-=50,cnt50--;
      while(charge>=20 && cnt20)
        charge-=20,cnt20--;
      while(charge>=10 && cnt10)
        charge-=10,cnt10--;
      while(charge>=5 && cnt5)
        charge-=5,cnt5--;
      while(charge>=1 && cnt1)
        charge--,cnt1--;
      if(charge)flag=0;
    }
    if(flag)puts("yes");
    else puts("no");
  }
}
