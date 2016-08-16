/*************************************************************************
     File Name: 158b.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月04日 星期四 19时53分00秒
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
int flag[10];

int main(){
  int n,x;
  while(~scanf("%d",&n)){
    Mem0(flag);
    while(n--){
      scanf("%d",&x);
      flag[x]++;
    }
    n=flag[4]+flag[3]+flag[2]/2;
    flag[1]-=flag[3];
    if(flag[2]%2)n++,flag[1]-=2;
    if(flag[1]>0)n+=(flag[1]+3)/4;
    printf("%d\n",n);
  }
}
