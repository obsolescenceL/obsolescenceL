/*************************************************************************
     File Name: UVALive5818.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五  8/26 20:30:41 2016
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
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=110;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N*N];
int v[N],sum,ans,tot;

void AddEdge(int from,int to) {
  Edge *p=&e[++tot];
  p->to=to,p->next=head[from],head[from]=p;
}

void dfs(int ch) {
  int maxn=0;
  for (Edge *p=head[ch]; p; p=p->next)
    if (v[p->to]>maxn) {
      maxn=v[p->to];
      ans=p->to;
    }
  if (maxn) sum+=maxn,dfs(ans);
}

int main() {
  int t,n,m,i,p1,p2;
  while (~scanf("%d",&t)) {
    for (int nc=1; nc<=t; ++nc) {
      printf("Case %d: ",nc);
      tot=-1,MEM0(head);
      scanf("%d%d",&n,&m);
      for (i=0; i<n; ++i) scanf("%d",v+i);
      while (m--) {
        scanf("%d%d",&p1,&p2);
        AddEdge(p1,p2);
      }
      sum=ans=0;
      dfs(0);
      printf("%d %d\n",sum,ans);
    }
  }
}
