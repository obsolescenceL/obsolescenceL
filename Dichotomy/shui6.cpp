/*************************************************************************
     File Name: shui6.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月06日 星期一 14时32分46秒
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
using namespace std;


int main(){
  int n,k,c,ans;
  while(~scanf("%d",&n)){
    k=0,c=1;
    while(k+c*5<n) k+=c*5,c*=2;//!!!
    n--;
    ans=(n-k)/c;
    if(!ans)puts("Sheldon");
    else if(ans==1)puts("Leonard");
    else if(ans==2)puts("Penny");
    else if(ans==3)puts("Rajesh");
    else puts("Howard");
  }
}
