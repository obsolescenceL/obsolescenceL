/*************************************************************************
     File Name: F.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月31日 星期日 23时41分52秒
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
const int N=1010,INF=0x3f3f3f3f;
struct Edge{
  int to,w,l;
  Edge *next;
}*head[N],e[N*N];
int top,s,t,dis[N];

void addEdge(int from,int to,int v,int limit) {
  Edge *p=&e[++top];
  p->to=to,p->w=v,p->l=limit,p->next=head[from],head[from]=p;
}

void spfa(int limit) {
  queue<int> q;
  bool vis[N];
  Mem0(vis),MemX(dis);
  dis[s]=0;
  q.push(s);
  vis[s]=1;
  int x,to;
  while (!q.empty()) {
    x=q.front();
    q.pop();
    vis[x]=0;
    for (Edge *p=head[x]; p; p=p->next) {
      to=p->to;
      if (dis[to]>dis[x]+p->w && p->l>=limit) {
        dis[to]=dis[x]+p->w;
        if (!vis[to]) {
          vis[to]=1;
          q.push(to);
        }
      }
    }
  }
}

int main() {
  int nc=0,n,m,p1,p2,v,l,i;
  while (~scanf("%d%d",&n,&m) && (n||m)) {
    Mem0(head),top=0;
    for (i=0; i<m; ++i) {
      scanf("%d%d%d%d",&p1,&p2,&l,&v);
      if (l==-1) l=INF;
      addEdge(p1,p2,v,l);
      addEdge(p2,p1,v,l);
    }
    scanf("%d%d%d",&s,&t,&l);
    int low=0,high=l,mid,ansH=0,ansL=-1;
    while (low<=high) {
      mid=(low+high)>>1;
      spfa(mid);
      if (dis[t]!=INF) {
        ansH=mid,ansL=dis[t];
        low=mid+1;
      } else high=mid-1;
    }
    if (nc) puts("");
    printf("Case %d:\n",++nc);
    if (ansL==-1) puts("cannot reach destination");
    else {
      printf("maximum height = %d\n",ansH);
      printf("length of shortest route = %d\n",ansL);
    }
  }
}
