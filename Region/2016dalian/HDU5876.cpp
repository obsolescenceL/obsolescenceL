/*************************************************************************
     File Name: 1009.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  9/10 12:22:07 2016
 ************************************************************************/
#pragma comment(linker, "/STACK:102400000,102400000")
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
#include<set>
#include<queue>
using namespace std;
const int N=2*1e6+10,M=55100,INF=0x3f3f3f3f;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[M<<1];

int s,n,tot,dis[N];

void AddEdge(int from,int to) {
  Edge *p=&e[++tot];
  p->to=to,p->next=head[from],head[from]=p;
}

void init() {
  tot=0;
  MEM0(head);
}

void bfs() {
  set<int> ta,tb;
  queue<int> q;
  q.push(s);
  int u,v,i,cnt;
  for (i=1; i<=n; ++i)
    if (i!=s) ta.insert(i);
  while (!q.empty()) {
    u=q.front();
    q.pop();
    for (Edge *p=head[u]; p; p=p->next) {
      v=p->to;
      if (!ta.count(v)) continue;
      ta.erase(v);
      tb.insert(v);
    }
    EACH(it,ta) {
      q.push(*it);
      dis[*it]=MIN(dis[*it],dis[u]+1);
    }
    ta.swap(tb);
    tb.clear();
  }
  for (i=1,cnt=0; i<=n; ++i) {
    if (dis[i]==INF) dis[i]=-1;
    if (i!=s) cnt++,printf("%d%c",dis[i]," \n"[cnt==n-1]);
  }
}

int main() {
  int t,m,p1,p2,i;
  while (~scanf("%d",&t)) {
    while (t--) {
      init();
      scanf("%d%d",&n,&m);
      while (m--) {
        scanf("%d%d",&p1,&p2);
        AddEdge(p1,p2),AddEdge(p2,p1);
      }
      scanf("%d",&s);
      for (i=1; i<=n; ++i) dis[i]=1;
      dis[s]=0;
      for (Edge *p=head[s]; p; p=p->next)
        dis[p->to]=INF;
      bfs();
    }
  }
}
