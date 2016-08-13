/*************************************************************************
     File Name: bc_c.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月26日 星期日 9时50分52秒
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
const int N=1e5;
int biao[N],n;

void init(){
  for(int i=1;;++i){
    biao[i]=3*i*(i-1)+1;
    if(biao[i]>1e9){n=i;break;}
  }
}

int main(){
  int t,m,i,pos;
  init();
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&m);
      bool flag=0;
      pos=lower_bound(biao+1,biao+1+n,m)-biao;
      if(biao[pos]==m)puts("1"),flag=1;
      if(flag)continue;
      int l=1,r=n;
      while(l<=r){
        if(biao[l]+biao[r]<m)break;
        while(l<=r){
          if(biao[l]+biao[r]<m){
            r++;
            break;
          }else if(biao[l]+biao[r]==m){
            puts("2"),flag=1;
            break;
          }else r--;
        }
        if(flag)break;
        l++;
      }
      if(flag)continue;
      for(i=3;(m-i)%6;++i);
      printf("%d\n",i);
    }
  }
}
