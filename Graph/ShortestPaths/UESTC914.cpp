/*************************************************************************
     File Name: 4_6c.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月06日 星期一 16时29分33秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>
#include<bitset>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1001;
int top,n,v[100*N],u[100*N],t[100*N];
bool vis[N];
struct Edge{
  int to,w;
  Edge *next;
}*head[N],e[100*N];
struct node{
  int to,w;
  bool operator < (const node& rhs) const {
    return w>rhs.w;
  }
}dis[2][N];

void Addedge(int from,int to,int val){
  Edge *p=&e[++top];
  p->to=to,p->w=val,p->next=head[from],head[from]=p;
}

void Dij(int s,int way){
  for(int i=1;i<=n;++i)dis[way][i].to=i,dis[way][i].w=INF;
  priority_queue<node> q;
  memset(vis,0,sizeof vis);
  dis[way][s].w=0;
  q.push(dis[way][s]);
  while(!q.empty()){
    node x=q.top();q.pop();
    int u=x.to;
    if(vis[u])continue;
    vis[u]=1;
    for(Edge *p=head[u];p;p=p->next){
      int to=p->to;
      if(!vis[to] && (dis[way][to].w>dis[way][u].w+p->w)){
        dis[way][to].w=dis[way][u].w+p->w;
        q.push(dis[way][to]);
      }
    }
  }
}

int main(){
  int m,x,i;
  while(~scanf("%d%d%d",&n,&m,&x)){
    memset(head,0,sizeof head);
    top=0;
    for(i=0;i<m;++i){
      scanf("%d%d%d",&u[i],&v[i],&t[i]);
      Addedge(u[i],v[i],t[i]);
    }
    Dij(x,0);
    memset(head,0,sizeof head);
    top=0;
    for(i=0;i<m;++i)Addedge(v[i],u[i],t[i]);
    Dij(x,1);
    int ans=0;
    for(i=1;i<=n;++i)ans=Max(ans,dis[0][i].w+dis[1][i].w);
    printf("%d\n",ans);
  }
}
