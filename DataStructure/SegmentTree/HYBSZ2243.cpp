/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 四 10/20 20:22:46 2016
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
using namespace std;
const int N=1e5+10;
struct Tree {
  int cnt,lc,rc;
  bool flag;
}tree[N<<2];

struct Edge {
  int to;
  Edge *next;
}*head[N],e[N<<1];

int top[N],sz[N],dep[N],pre[N],tot,son[N],id[N],c[N],pos[N];

void AddEdge(int to,int from) {
  Edge *p=&e[++tot];
  p->to=to,p->next=head[from],head[from]=p;
}

void pushUp(int t) {
  tree[t].lc=tree[t<<1].lc;
  tree[t].rc=tree[t<<1|1].rc;
  tree[t].cnt=tree[t<<1].cnt+tree[t<<1|1].cnt;
  if (tree[t<<1].rc==tree[t<<1|1].lc)
    tree[t].cnt--;
}

void pushDown(int t) {
  if (!tree[t].flag) return;
  tree[t<<1].cnt=tree[t<<1|1].cnt=1;
  tree[t<<1].lc=tree[t<<1].rc=tree[t<<1|1].lc=tree[t<<1|1].rc=tree[t].lc;
  tree[t<<1].flag=tree[t<<1|1].flag=tree[t].flag;
  tree[t].flag=0;
}

void build(int t,int L,int R) {
  tree[t].flag=0;
  if (L==R) {
    tree[t].cnt=1;
    tree[t].lc=tree[t].rc=c[pos[L]];
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
  pushUp(t);
}

void update(int t,int L,int R,int l,int r,int v) {
  if (l<=L && R<=r) {
    tree[t].cnt=1;
    tree[t].lc=tree[t].rc=v;
    tree[t].flag=1;
    return;
  }
  pushDown(t);
  int mid=(L+R)>>1;
  if (l<=mid) update(t<<1,L,mid,l,r,v);
  if (r>mid) update(t<<1|1,mid+1,R,l,r,v);
  pushUp(t);
}

int queryCnt(int t,int L,int R,int l,int r) {
  if (l<=L && R<=r) return tree[t].cnt;
  int mid=(L+R)>>1,ans=0;
  pushDown(t);
  if (r<=mid) return queryCnt(t<<1,L,mid,l,r);
  else if (l>mid) return queryCnt(t<<1|1,mid+1,R,l,r);
  else {
    ans=queryCnt(t<<1,L,mid,l,r)+queryCnt(t<<1|1,mid+1,R,l,r);
    if (tree[t<<1].rc==tree[t<<1|1].lc) ans--;
    return ans;
  }
}

int queryCol(int t,int L,int R,int x) {
  if (L==R && L==x) return tree[t].lc;
  int mid=(L+R)>>1;
  pushDown(t);
  if (x<=mid) return queryCol(t<<1,L,mid,x);
  return queryCol(t<<1|1,mid+1,R,x);
}

void dfs1(int x,int fa,int de) {
  sz[x]=1;
  dep[x]=de;
  pre[x]=fa;
  son[x]=0;
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
    if (p->to==son[x]) continue;
    if (p->to==pre[x]) continue;
    dfs2(p->to,p->to);
  }
}

int main() {
  int n,m,i,x,y,v;
  char op[20];
  while (~scanf("%d%d",&n,&m)) {
    tot=0,MEM0(head),MEM0(tree),MEM0(sz),MEM0(dep);
    for (i=1; i<=n; ++i) scanf("%d",c+i);
    for (i=1; i<n; ++i) {
      scanf("%d%d",&x,&y);
      AddEdge(x,y);
      AddEdge(y,x);
    }
    tot=0;
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,tot);
    for (i=1; i<=m; ++i) {
      scanf("%s%d%d",op,&x,&y);
      if (op[0]=='C') {
        scanf("%d",&v);
        while (top[x] != top[y]) {
          if (dep[top[x]] < dep[top[y]])
            swap(x,y);
          update(1,1,tot,id[top[x]],id[x],v);
          x=pre[top[x]];
        }
        if (dep[x] > dep[y]) swap(x,y);
        update(1,1,tot,id[x],id[y],v);
      } else {
        int ans=0;
        while (top[x] != top[y]) {
          if (dep[top[x]] < dep[top[y]])
            swap(x,y);
          ans+=queryCnt(1,1,tot,id[top[x]],id[x]);
          if (queryCol(1,1,tot,id[top[x]]) == queryCol(1,1,tot,id[pre[top[x]]])) ans--;
          x=pre[top[x]];
        }
        if (dep[x] > dep[y]) swap(x,y);
        ans+=queryCnt(1,1,tot,id[x],id[y]);
        printf("%d\n",ans);
      }
    }
  }
}
