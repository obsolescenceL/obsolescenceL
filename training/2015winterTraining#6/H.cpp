/*************************************************************************
     File Name: H.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月24日 星期日 13时54分42秒
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
  double d[10];
  while(scanf("%lf%lf%lf",d,d+1,d+2)&&(d[0]||d[1]||d[2])){
    sort(d,d+3);
    if(d[0]<0.25 || d[1]<90.0 || d[2]<125.0)
      puts("not mailable");
    else if(d[0]<=7.0 && d[1]<=155.0 && d[2]<=290.0)
      puts("letter");
    else if((d[0]>7.0 || d[1]>155.0 || d[2]>290.0) && d[0]<=50.0 && d[1]<=300.0 && d[2]<=380.0)
      puts("packet");
    else if((d[0]>50.0 || d[1]>300.0 || d[2]>380.0) && (d[0]+d[1])*2+d[2]<=2100.0)
      puts("parcel");
    else puts("not mailable");
  }
}
