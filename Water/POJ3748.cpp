/*************************************************************************
     File Name: 4_4f.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月04日 星期六 17时01分04秒
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
using namespace std;



int main(){
  int r,x,y;
  while(~scanf("%x,%d,%d",&r,&x,&y)){
    bitset<32> b(r);
    b.reset(x);
    b.set(y);
    b.set(y-1);
    b.reset(y-2);
    printf("%x\n",b.to_ulong());
  }
}
