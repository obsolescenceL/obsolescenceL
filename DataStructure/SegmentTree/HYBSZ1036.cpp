/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五 10/21 10:08:45 2016
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
using namespace std;
const int N=3e4+10,INF=0x3f3f3f3f;
struct Edge {
  int to;
  Edge *next;
}*head[N],e[N<<1];

struct Tree {
  int maxx,sum;
}tree[N<<2];

int top[N],son[N],pre[N],dep[N],sz[N],id[N],tot,maxn,sum,c[N],pos[N];

void AddEdge(int from,int to) {
  Edge *p=&e[++tot];
  p->to=to,p->next=head[from],head[from]=p;
}

void dfs1(int x,int fa,int de) {
  sz[x]=1;
  son[x]=0;
  pre[x]=fa;
  dep[x]=de;
  for (Edge *p=head[x]; p; p=p->next) {
    if (p->to==fa) continue;
    dfs1(p->to,x,de+1);
    sz[x]+=sz[p->to];
    if (sz[p->to] > sz[son[x]]) son[x]=p->to;
  }
}

void dfs2(int x,int tp) {
  top[x]=tp;
  id[x]=++tot;
  pos[tot]=x;
  if (son[x]) dfs2(son[x],tp);
  for (Edge *p=head[x]; p; p=p->next) {
    if (p->to==son[x] || p->to==pre[x])
      continue;
    dfs2(p->to,p->to);
  }
}

void pushUp(int t) {
  tree[t].maxx=MAX(tree[t<<1].maxx,tree[t<<1|1].maxx);
  tree[t].sum=tree[t<<1].sum+tree[t<<1|1].sum;
}

void build(int t,int L,int R) {
  if (L==R) {
    tree[t].maxx=tree[t].sum=c[pos[L]];
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
  pushUp(t);
}

void update(int t,int L,int R,int x,int v) {
  if (L==R) {
    tree[t].maxx=tree[t].sum=v;
    return;
  }
  int mid=(L+R)>>1;
  if (x<=mid) update(t<<1,L,mid,x,v);
  else update(t<<1|1,mid+1,R,x,v);
  pushUp(t);
}

void query_max(int t,int L,int R,int l,int r) {
  if (l<=L && R<=r) {
    maxn=MAX(maxn,tree[t].maxx);
    return;
  }
  int mid=(L+R)>>1;
  if (l<=mid) query_max(t<<1,L,mid,l,r);
  if (r>mid) query_max(t<<1|1,mid+1,R,l,r);
}

void query_sum(int t,int L,int R,int l,int r) {
  if (l<=L && R<=r) {
    sum+=tree[t].sum;
    return;
  }
  int mid=(L+R)>>1;
  if (l<=mid) query_sum(t<<1,L,mid,l,r);
  if (r>mid) query_sum(t<<1|1,mid+1,R,l,r);
}

int main() {
  int n,i,x,y,v,m;
  char op[10];
  while (~scanf("%d",&n)) {
    tot=0,MEM0(head);
    for (i=1; i<n; ++i) {
      scanf("%d%d",&x,&y);
      AddEdge(x,y);
      AddEdge(y,x);
    }
    tot=0;
    dfs1(1,0,1);
    dfs2(1,1);
    for (i=1; i<=n; ++i) scanf("%d",c+i);
    build(1,1,tot);
    scanf("%d",&m);
    for (i=1; i<=m; ++i) {
      scanf("%s%d%d",op,&x,&y);
      if (op[0]=='C') {
        update(1,1,tot,id[x],y);
      } else if (op[1]=='M') {
        maxn=-INF;
        while (top[x] != top[y]) {
          if (dep[top[x]] < dep[top[y]])
            swap(x,y);
          query_max(1,1,tot,id[top[x]],id[x]);
          x=pre[top[x]];
        }
        if (dep[x] > dep[y]) swap(x,y);
        query_max(1,1,tot,id[x],id[y]);
        printf("%d\n",maxn);
      } else {
        sum=0;
        while (top[x] != top[y]) {
          if (dep[top[x]] < dep[top[y]])
            swap(x,y);
          query_sum(1,1,tot,id[top[x]],id[x]);
          x=pre[top[x]];
        }
        if (dep[x] > dep[y]) swap(x,y);
        query_sum(1,1,tot,id[x],id[y]);
        printf("%d\n",sum);
      }
    }
  }
}
