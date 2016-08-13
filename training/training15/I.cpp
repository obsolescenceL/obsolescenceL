/*************************************************************************
     File Name: I.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月03日 星期一 15时36分25秒
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
  int n,i;
  while(~scanf("%d",&n)){
    if(n<4)puts("NO");
    else if(n%2){
      puts("YES");
      puts("5 * 4 = 20");
      puts("20 + 3 = 23");
      puts("23 + 2 = 25");
      puts("25 - 1 = 24");
      for(i=6;i<=n-1;i+=2){
        printf("%d - %d = 1\n",i+1,i);
        puts("24 * 1 = 24");
      }
    }else{
      puts("YES");
      puts("1 * 2 = 2");
      puts("2 * 3 = 6");
      puts("6 * 4 = 24");
      for(i=5;i<=n-1;i+=2){
        printf("%d - %d = 1\n",i+1,i);
        puts("24 * 1 = 24");
      }
    }
  }
}
