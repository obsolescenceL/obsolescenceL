/*************************************************************************
     File Name: H.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月27日 星期一 14时02分36秒
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
const int N=5;
double a[N],b[N],k[N];

int main(){
  int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
  while(~scanf("%d%d",&x1,&y1)){
    scanf("%d%d",&x2,&y2);
    scanf("%d%d",&x3,&y3);
    a[1]=(double)(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    a[2]=(double)(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
    a[3]=(double)(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
    scanf("%d%d",&x4,&y4);
    scanf("%d%d",&x5,&y5);
    scanf("%d%d",&x6,&y6);
    b[1]=(double)(x4-x5)*(x4-x5)+(y4-y5)*(y4-y5);
    b[2]=(double)(x4-x6)*(x4-x6)+(y4-y6)*(y4-y6);
    b[3]=(double)(x6-x5)*(x6-x5)+(y6-y5)*(y6-y5);
    sort(a+1,a+3+1);
    sort(b+1,b+3+1);
    for(int i=1;i<=3;++i)
      k[i]=a[i]/b[i];
    if(k[1]==k[2] && k[2]==k[3])puts("YES");
    else puts("NO");
  }
}
