/*************************************************************************
     File Name: G.cpp
     ID: obsoles1
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五 10/21 13:57:34 2016
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
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5e4+10;
typedef long long LL;
struct Edge {
  int to;
  Edge *next;
}*head[N],e[N<<1];
LL tree[N<<2],sum;
int top[N],id[N],dep[N],sz[N],son[N],pre[N],tot,pos[N],a[N],b[N],c[N];

void pushUp(int t) {
  tree[t]=tree[t<<1]+tree[t<<1|1];
}

void update(int t,int L,int R,int x,int v) {
  if (L==R) {
    tree[t]=v;
    return;
  }
  int mid=(L+R)>>1;
  if (x<=mid) update(t<<1,L,mid,x,v);
  else update(t<<1|1,mid+1,R,x,v);
  pushUp(t);
}

void query(int t,int L,int R,int l,int r) {
  if (l<=L && R<=r) {
    sum+=tree[t];
    return;
  }
  int mid=(L+R)>>1;
  if (l<=mid) query(t<<1,L,mid,l,r);
  if (r>mid) query(t<<1|1,mid+1,R,l,r);
}

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
    if (p->to==pre[x] || p->to==son[x])
      continue;
    dfs2(p->to,p->to);
  }
}

int main() {
  int n,m,i,op,x,y;
  while (~scanf("%d%d",&n,&m)) {
    tot=0,MEM0(head);
    for (i=1; i<n; ++i) {
      scanf("%d%d%d",a+i,b+i,c+i);
      AddEdge(a[i],b[i]);
      AddEdge(b[i],a[i]);
    }
    tot=0;
    dfs1(1,0,1);
    dfs2(1,1);
    for (i=1; i<n; ++i) {
      if (dep[a[i]] < dep[b[i]])
        swap(a[i],b[i]);
      update(1,1,tot,id[a[i]],c[i]);
    }
    for (i=1; i<=m; ++i) {
      scanf("%d%d%d",&op,&x,&y);
      if (op) {
        sum=0;
        while (top[x] != top[y]) {
          if (dep[top[x]] < dep[top[y]])
            swap(x,y);
          query(1,1,tot,id[top[x]],id[x]);
          x=pre[top[x]];
        }
        if (x!=y) {
          if (dep[x] > dep[y]) swap(x,y);
          query(1,1,tot,id[son[x]],id[y]);
        }
        printf("%I64d\n",sum);
      } else update(1,1,tot,id[a[x]],y);
    }
  }
}
