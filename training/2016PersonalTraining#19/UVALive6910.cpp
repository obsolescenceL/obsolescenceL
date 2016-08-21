/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日  8/21 13:20:21 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int N=20010,M=5010;
int n,a[N],pre[N],ans[M];
struct node{
  char op[2];
  int a,b;
}query[M];
bool mark[N],flag[M];

int find(int x) {
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

void Union(int x,int y) {
  x=find(x),y=find(y);
  pre[x]=y;
}

void init() {
  MEM0(mark),MEM0(flag);
  for (int i=0; i<=n; ++i) pre[i]=i;
}

int main() {
  int t,k,i;
  while (~scanf("%d",&t)) {
    for (int nc=1; nc<=t; ++nc) {
      scanf("%d%d",&n,&k);
      init();
      for (i=1; i<=n; ++i) scanf("%d",a+i);
      for (i=1; i<=k; ++i) {
        scanf("%s%d",query[i].op,&query[i].a);
        if (query[i].op[0]=='Q')
          scanf("%d",&query[i].b);
        else if (!mark[query[i].a]) {
          mark[query[i].a]=1;
          flag[i]=1;
        }
      }
      for (i=1; i<=n; ++i)
        if (!mark[i] && a[i]) Union(i,a[i]);
      for (i=k; i>=1; --i) {
        int x=query[i].a,y=query[i].b;
        if (query[i].op[0]=='Q') {
          int fx=find(x),fy=find(y);
          if (fx==fy) ans[i]=1;
          else ans[i]=0;
        } else if(flag[i] && a[x]) Union(x,a[x]);
      }
      printf("Case #%d:\n",nc);
      for (i=1; i<=k; ++i)
        if (query[i].op[0]=='Q') {
          if (ans[i]) puts("YES");
          else puts("NO");
        }
    }
  }
}
