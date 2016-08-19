/*************************************************************************
     File Name: K.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 四  8/18 16:05:56 2016
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
#include<queue>
#include<cstring>
using namespace std;
const int N=1e5+10;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N<<1];
int tot,dis[2][N],dp[N];
bool vis[N];

void AddEdge(int from,int to) {
  Edge *p=&e[++tot];
  p->to=to,p->next=head[from],head[from]=p;
}

void SPFA(int s,int way) {
  MEMX(dis[way]);
  queue<int>  q;
  MEM0(vis);
  dis[way][s]=0,q.push(s),vis[s]=1;
  int x,to;
  while (!q.empty()) {
    x=q.front(),q.pop(),vis[x]=0;
    for (Edge *p=head[x]; p; p=p->next) {
      to=p->to;
      if (dis[way][to] > dis[way][x]+1) {
        dis[way][to]=dis[way][x]+1;
        if (!vis[to]) vis[to]=1,q.push(to);
      }
    }
  }
}

int main() {
  int n,m,p1,p2,s,f,r,x,to;
  while (~scanf("%d%d",&n,&m)) {
    while (m--) {
      scanf("%d%d",&p1,&p2);
      AddEdge(p1,p2);
      AddEdge(p2,p1);
    }
    scanf("%d%d%d",&s,&f,&r);
    //cout<<"s="<<s<<" f="<<f<<" r="<<r<<endl;
    SPFA(f,0);
    SPFA(r,1);
    MEM0(dp),MEM0(vis);
    dp[s]=dis[1][s],vis[s]=1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      x=q.front(),q.pop();
      dis[1][x]=MIN(dis[1][x],dp[x]);
      for (Edge *p=head[x]; p; p=p->next) {
        to=p->to;
        if (dis[0][x]-dis[0][to] == 1) {
          dp[to]=MAX(dp[to],dis[1][x]);
          //cout<<"dp["<<to<<"]="<<dp[to]<<endl;
          //cout<<"dis[1]["<<x<<"]="<<dis[1][x]<<endl;
          if (!vis[to]) vis[to]=1,q.push(to);
        }
      }
    }
    printf("%d\n",dis[1][f]);
  }
}
