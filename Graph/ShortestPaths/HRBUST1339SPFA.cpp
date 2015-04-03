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
#include<queue>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
const int INF=0x3f3f3f3f;
const int N=5010;
using namespace std;
int n,top;
struct Edge{
  int to,weight;
  Edge *next;
}*head[N],e[N*4];

int dis[3][N];

void Addedge(int from,int to,int val){
  Edge *p=&e[++top];
  p->to=to,p->weight=val,p->next=head[from],head[from]=p;
}

void spfa(const int& s,const int& way){
  queue<int> q;
  bool vis[N];
  memset(vis,0,sizeof vis);
  dis[way][s]=0;
  q.push(s);
  vis[s]=1;
  int x,to;
  while(!q.empty()){
    x=q.front();
    q.pop();
    vis[x]=0;
    for(Edge *p=head[x];p;p=p->next){
      to=p->to;
      if(dis[way][to]>dis[way][x]+p->weight){
        dis[way][to]=dis[way][x]+p->weight;
        if(!vis[to]){
          vis[to]=1;
          q.push(to);
        }
      }
    }
  }
}

int main(){
  int a,b,c,m,nc=0,x,y,v,i,sum;
  while(~scanf("%d%d",&n,&m)){
    memset(head,0,sizeof head);
    memset(dis,0x3f,sizeof dis);
    top=0;
    scanf("%d%d%d",&c,&a,&b);
    while(m--){
      scanf("%d%d%d",&x,&y,&v);
      Addedge(x,y,v);
      Addedge(y,x,v);
    }
    spfa(c,0);
    spfa(a,1);
    spfa(b,2);
    sum=INF;
    for(i=1;i<=n;++i)
      sum=Min(sum,(long long)dis[0][i]+dis[1][i]+dis[2][i]);
    printf("Scenario #%d\n%d\n\n",++nc,sum);
  }
}
