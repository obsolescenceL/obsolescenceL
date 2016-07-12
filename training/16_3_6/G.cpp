/*************************************************************************
     File Name: G.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日  3/ 6 14:48:00 2016
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
struct node{
  int x,y;
}p[N];
struct sprinkler{
  int x,y,r;
}sp[N];
 
int main(){
  int n,m,i,j;
  while(~scanf("%d",&n)){
    for(i=0;i<n;++i)
      scanf("%d%d",&p[i].x,&p[i].y);
    scanf("%d",&m);
    for(i=0;i<m;++i)
      scanf("%d%d%d",&sp[i].x,&sp[i].y,&sp[i].r);
    int sum=n,x,y;
    for(i=0;i<n;++i)
      for(j=0;j<m;++j){
        x=(p[i].x-sp[j].x)*(p[i].x-sp[j].x);
        y=(p[i].y-sp[j].y)*(p[i].y-sp[j].y);
        if(x+y<=sp[j].r*sp[j].r){
          sum--;
          break;
        }
      }
    printf("%d\n",sum);
  }
}
