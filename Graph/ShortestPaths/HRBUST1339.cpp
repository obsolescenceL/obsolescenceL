/*************************************************************************
     File Name: 4_1d.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月02日 星期四 22时24分28秒
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
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
const int INF=0x3f3f3f3f;
const int N=5010;
using namespace std;
int n,top=0;
bool vis[N];
struct Edge{
  int to,weight;
  Edge *next;
}*head[N],e[N*4];

struct node{
  int to,weight;
  bool operator < (const node& rhs) const {
    return weight>rhs.weight;
  }
}dis[3][N];

void Addedge(int from,int to,int val){
  Edge *p=&e[++top];
  p->to=to,p->weight=val,p->next=head[from],head[from]=p;
}

void dij(int s,int way){
  for(int i=1;i<=n;++i)dis[way][i].to=i,dis[way][i].weight=INF;
  priority_queue<node> q;
  memset(vis,0,sizeof vis);
  dis[way][s].weight=0;
  q.push(dis[way][s]);
  //vis[s]=1;
  while(!q.empty()){
    node x=q.top();q.pop();
    int u=x.to;
    if(vis[u])continue;
    vis[u]=1;
    for(Edge *p=head[u];p;p=p->next){
      int to=p->to;
      if( !vis[to] && (dis[way][to].weight>dis[way][u].weight+p->weight)){
        dis[way][to].weight=dis[way][u].weight+p->weight;
        q.push(dis[way][to]);
      }
    }
  }
}

int main(){
  int a,b,c,m,nc=0,x,y,v,i,sum;
  while(~scanf("%d%d",&n,&m)){
    memset(head,0,sizeof head);
    top=0;
    scanf("%d%d%d",&c,&a,&b);
    for(i=0;i<m;++i){
      scanf("%d%d%d",&x,&y,&v);
      Addedge(x,y,v);
      Addedge(y,x,v);
    }
    dij(c,0);
    dij(a,1);
    dij(b,2);
    sum=INF;
    for(i=1;i<=n;++i)
      sum=Min(sum,(long long)dis[0][i].weight+dis[1][i].weight+dis[2][i].weight);
    printf("Scenario #%d\n%d\n\n",++nc,sum);
  }
}
