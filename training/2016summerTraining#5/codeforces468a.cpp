/*************************************************************************
     File Name: F.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月26日 星期二 13时07分42秒
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
  int n;
  while(~scanf("%d",&n)){
    if(n<4)puts("NO");
    else{
      puts("YES");
      while(n>5){
        printf("%d - %d = 1\n",n,n-1);
        n-=2;
        printf("%d * 1 = %d\n",n,n);
      }
      if(n==5)puts("5 * 3 = 15\n4 * 2 = 8\n15 + 1 = 16\n16 + 8 = 24");
      if(n==4)puts("4 * 3 = 12\n12 * 2 = 24\n24 * 1 = 24");
    }
  }
}
