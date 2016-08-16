/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月28日 星期二 12时23分31秒
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
const int N=100010;
struct Clock{
  int h,m,s;
  bool operator < (const Clock &rhs) const {
    return h<rhs.h || (h==rhs.h && m<rhs.m) || (h==rhs.h && m==rhs.m && s<rhs.s);
  }
}c[N],ans[N];

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    for(i=0;i<n;++i)
      scanf("%d%d%d",&c[i].h,&c[i].m,&c[i].s);
    sort(c,c+n);
    for(i=0;i<n;++i){

      //cout<<"c["<<i<<"]("<<c[i].h<<','<<c[i].m<<','<<c[i].s<<")\n";
    }
  }
}
