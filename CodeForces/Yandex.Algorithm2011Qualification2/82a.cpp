/*************************************************************************
     File Name: 82a.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月05日 星期五 02时41分24秒
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
  int n;
  while(~scanf("%d",&n)){
    int k=0,c=1;
    while(k+c*5<n){
      k+=c*5;
      c*=2;
    }
    n--;
    int ans=(n-k)/c;
    if(!ans)puts("Sheldon");
    else if(ans==1)puts("Leonard");
    else if(ans==2)puts("Penny");
    else if(ans==3)puts("Rajesh");
    else puts("Howard");
  }
}
