/*************************************************************************
     File Name: HDU2874.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月02日 星期二 09时33分22秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<vector>
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
const int N=10010;
struct Edge{
  int to,v;
  Edge *next;
}*head[N],*qes[N],e[101*N<<1];
int n,top,pre[N],d[N],ans[N*100],vis[N];

void addEdge(int from,int to,int v) {
  Edge *p=&e[++top];
  p->to=to,p->v=v,p->next=head[from],head[from]=p;
}

void addEdge2(int from,int to,int v) {
  Edge *p=&e[++top];
  p->to=to,p->v=v,p->next=qes[from],qes[from]=p;
}

int find(int x) {
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

void Union(int x,int y) {
  x=find(x),y=find(y);
  if (x!=y) pre[y]=x;
}

void TarjanLca(int u,int i) {
  vis[u]=i;
  for (Edge *p=head[u]; p; p=p->next) {
    if (vis[p->to]) continue;
    d[p->to]+=d[u]+p->v;
    TarjanLca(p->to,i);
    Union(u,p->to);
  }
  for (Edge *p=qes[u]; p; p=p->next)
    if (vis[p->to]==i) {
      ans[p->v]=d[u]+d[p->to]-2*d[find(p->to)];
      //printf("d[%d]=%d\n",u,d[u]);
    }
}

void init() {
  Mem0(d),Mem0(head),Mem1(ans),Mem0(vis);
  Mem0(qes);
  for (int i=0; i<=n; ++i) pre[i]=i;
  top=0;
}

int main() {
  int i,p1,p2,v,m,c;
  while (~scanf("%d%d%d",&n,&m,&c)) {
    init();
    for (i=0; i<m; ++i) {
      scanf("%d%d%d",&p1,&p2,&v);
      addEdge(p1,p2,v);
      addEdge(p2,p1,v);
    }
    for (i=0; i<c; ++i) {
      scanf("%d%d",&p1,&p2);
      addEdge2(p1,p2,i);
      addEdge2(p2,p1,i);
    }
    for (i=1; i<=n; ++i)
      if (!vis[i]) TarjanLca(i,i);
    for (i=0; i<c; ++i)
      if (ans[i]==-1)
        puts("Not connected");
      else printf("%d\n",ans[i]);
  }
}
