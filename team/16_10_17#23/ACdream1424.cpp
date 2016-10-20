/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 三 10/19 21:26:46 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e4+10;
struct Edge {
  int to;
  Edge *next;
}*head[N],e[N*10];

struct Seg {
  int x,y;
  Seg() {}
  Seg(int _x,int _y):x(_x),y(_y) {}
}seg[N*10];

struct Tree {
  int x,flag;
} tree[N<<2];

int sz[N],pre[N],son[N],dep[N],top[N],id[N],tot,ans;

void pushUp(int t) {
  tree[t].x=tree[t<<1].x+tree[t<<1|1].x;
}

void pushDown(int t,int L,int R) {
   if (!tree[t].flag) return;
   int mid=(L+R)>>1;
   tree[t<<1].x+=tree[t].flag*(mid-L+1);
   tree[t<<1|1].x+=tree[t].flag*(R-mid);
   tree[t<<1].flag+=tree[t].flag;
   tree[t<<1|1].flag+=tree[t].flag;
   tree[t].flag=0;
}

void update(int t,int L,int R,int l,int r) {
  if (l<=L && R<=r) {
    tree[t].x+=(R-L+1);
    tree[t].flag++;
    return;
  }
  pushDown(t,L,R);
  int mid=(L+R)>>1;
  if (l<=mid) update(t<<1,L,mid,l,r);
  if (r>mid) update(t<<1|1,mid+1,R,l,r);
  pushUp(t);
}

void query(int t,int L,int R) {
  if (L==R) {
    //cout<<"tree["<<L<<"].x="<<tree[t].x<<endl;
    if (tree[t].x<2 && L!=1) ans++;
    return;
  }
  pushDown(t,L,R);
  int mid=(L+R)>>1;
  query(t<<1,L,mid);
  query(t<<1|1,mid+1,R);
}

void AddEdge(int to,int from) {
  Edge *p=&e[++tot];
  p->to=to,p->next=head[from],head[from]=p;
}

void dfs(int x,int fa,int de) {
  sz[x]=1;
  pre[x]=fa;
  dep[x]=de;
  son[x]=0;
  for (Edge *p=head[x]; p; p=p->next) {
    if (p->to==fa) continue;
    dfs(p->to,x,de+1);
    sz[x]+=sz[p->to];
    if (sz[son[x]] < sz[p->to]) son[x]=p->to;
  }
}

void dfs_1(int x,int tp) {
  id[x]=++tot;
  top[x]=tp;
  if (son[x]) dfs_1(son[x],tp);
  for (Edge *p=head[x]; p; p=p->next) {
    if (p->to==son[x]) continue;
    if (p->to==pre[x]) continue;
    dfs_1(p->to,p->to);
  }
}

int main() {
  int n,m,p1,p2,v,cnt,i;
  while (~scanf("%d%d",&n,&m)) {
    tot=cnt=0;
    MEM0(head),MEM0(son),MEM0(tree);
    for (i=0; i<m; ++i) {
      scanf("%d%d%d",&p1,&p2,&v);
      if (v) {
        AddEdge(p1,p2);
        AddEdge(p2,p1);
      } else {
        //cout<<"p1="<<p1<<" p2="<<p2<<endl;
        seg[++cnt]=Seg(p1,p2);
      }
    }
    //cout<<"cnt="<<cnt<<endl;
    tot=0;
    dfs(1,-1,1);
    dfs_1(1,1);
    for (i=1; i<=cnt; ++i) {
      int x=seg[i].x,y=seg[i].y;
      //cout<<"id["<<x<<"]="<<id[x]<<" id["<<y<<"]="<<id[y]<<endl;
      while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
          swap(x,y);
        //cout<<"id["<<top[x]<<"]="<<id[top[x]]<<" id["<<x<<"]="<<id[x]<<endl;
        update(1,1,tot,id[top[x]],id[x]);
        x=pre[top[x]];
      }
      if (x==y) continue;
      if (dep[x] > dep[y]) swap(x,y);
      //cout<<"id["<<son[x]<<"]="<<id[son[x]]<<" id["<<y<<"]="<<id[y]<<endl;
      update(1,1,tot,id[son[x]],id[y]);
    }
    ans=0;
    query(1,1,tot);
    printf("%d\n",ans);
  }
}
