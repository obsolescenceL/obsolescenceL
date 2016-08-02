/*************************************************************************
     File Name: HDU2586.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月01日 星期一 20时23分39秒
 ************************************************************************/
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
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
const int N=40010;
struct Edge{
  int to,v;
  Edge *next;
}*head[N],e[N<<1];
struct node{
  int ord,x;
}tmp;
int n,top,pre[N],d[N],ans[N];
bool vis[N],root[N];
vector<node> qes[N];

void addEdge(int from,int to,int v) {
  Edge *p=&e[++top];
  p->to=to,p->v=v,p->next=head[from],head[from]=p;
}

int find(int x) {
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

void Union(int x,int y) {
  x=find(x),y=find(y);
  if (x!=y) pre[y]=x;
}


void TarjanLca(int u) {
  vis[u]=1;
  for (Edge *p=head[u]; p; p=p->next) {
    if (vis[p->to]) continue;
    d[p->to]+=d[u]+p->v;
    TarjanLca(p->to);
    Union(u,p->to);
  }
  each(i,qes[u])
    if (vis[i->x]) {
      ans[i->ord]=d[u]+d[i->x]-2*d[find(i->x)];
    }
}

void init(){
  Mem0(root),Mem0(vis),Mem0(d),Mem0(head);
  for (int i=0; i<=n; ++i)
    pre[i]=i,qes[i].clear();
  top=0;
}

int main() {
  int i,t,m,p1,p2,v;
  while (~scanf("%d",&t)) {
    while (t--) {
      scanf("%d%d",&n,&m);
      init();
      for (i=1; i<n; ++i) {
        scanf("%d%d%d",&p1,&p2,&v);
        addEdge(p1,p2,v);
        addEdge(p2,p1,v);
        root[p2]=1;
      }
      for (i=1; i<=m; ++i) {
        scanf("%d%d",&p1,&p2);
        tmp.ord=i;
        tmp.x=p2;
        qes[p1].pb(tmp);
        tmp.x=p1;
        qes[p2].pb(tmp);
      }
      for (i=1; i<=n; ++i)
        if (!root[i]) {
          TarjanLca(i);
          break;
        }
      for (i=1; i<=m; ++i)
        printf("%d\n",ans[i]);
    }
  }
}
