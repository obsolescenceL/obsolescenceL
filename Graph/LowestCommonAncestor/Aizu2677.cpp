/*************************************************************************
     File Name: Aizu2677.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月29日 星期五 21时13分37秒
 ************************************************************************/
#include<bits/stdc++.h>
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
const int N=1e5+10;
int n,top,pre[N],d[N],x[N];
bool vis[N],root[N];
ll ans;
vector<int> qes[N];
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N<<1];

void addEdge(int from,int to) {
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

int find(int x) {
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

void Union(int x,int y) {
  x=find(x),y=find(y);
  if (x!=y) pre[y]=x;
}

void TarjanLca(int u) {
  for (Edge *p=head[u]; p; p=p->next) {
    TarjanLca(p->to);
    Union(u,p->to);
  }
  vis[u]=1;
  for (auto i:qes[u])
    if (vis[i])
      ans+=d[u]+d[i]-2*d[find(i)];
}

void bfs() {
  queue<int> q;
  q.push(1);
  int s,t=1;
  while (!q.empty()) {
    s=q.front();
    q.pop();
    qes[t].pb(s);
    qes[s].pb(t);
    for (Edge *p=head[s]; p; p=p->next) {
      d[p->to]=d[s]+1;
      q.push(p->to);
    }
    t=s;
  }
}

void init() {
  Mem0(root),Mem0(vis),Mem0(d),Mem0(head);
  for (int i=0; i<=n; ++i)
    pre[i]=i,qes[i].clear();
  top=ans=0;
}

int main() {
  int i;
  while (~scanf("%d",&n)) {
    init();
    for (i=2; i<=n; ++i)
      scanf("%d",x+i);
    for (i=n; i>=2; --i) {
      addEdge(x[i],i);
      root[i]=1;
    }
    bfs();
    for (i=1; i<=n; ++i)
      if (!root[i]) {
        TarjanLca(i);
        break;
      }
    printf("%lld\n",ans);
  }
}
