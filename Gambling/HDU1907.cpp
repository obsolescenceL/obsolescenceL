/*************************************************************************
     File Name: HDU1907.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月14日 星期四 19时19分57秒
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
  int t,n,i,x;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&n);
      int cnt1=0,cnt2=0,sum=0;
      for(i=0;i<n;++i){
        scanf("%d",&x);
        if(x==1)cnt1++;
        if(x>1)cnt2++;
        sum^=x;
      }
      if(sum){
        if(n==cnt1)puts("Brother");
        else puts("John");
      }else{
        if(n!=cnt1)puts("Brother");
        else puts("John");
      }
    }
  }
}
