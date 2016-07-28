/*************************************************************************
     File Name: D.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月26日 星期二 12时31分32秒
 ************************************************************************/
//#include<bits/stdc++.h>
#include<cstdio>
#include<queue>
#include<cstring>
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
const int N=510,M=2510;
struct Edge{
  int to,v;
  Edge *next;
}*head[N],e[M*2+200];
int n,top,dis[N];

void Addedge(int from,int to,int v){
  Edge *p=&e[++top];
  p->to=to,p->v=v,p->next=head[from],head[from]=p;
}

bool spfa(int s){
  queue<int> q;
  bool vis[N];
  int x,to,cnt[N];
  Mem0(vis),Mem0(cnt);
  dis[s]=0;
  vis[s]=1;
  q.push(s);
  cnt[s]++;
  while(!q.empty()){
    x=q.front(),q.pop();
    vis[x]=0;
    if(cnt[x]>=n)return 0;
    for(Edge *p=head[x];p;p=p->next){
      to=p->to;
      if(dis[to] > dis[x]+p->v){
        dis[to]=dis[x]+p->v;
        if(!vis[to]){
          vis[to]=1;
          cnt[to]++;
          q.push(to);
        }
      }
    }
  }
  return 1;
}

int main(){
  int t,m,w,i,p1,p2,v;
  while(~scanf("%d",&t)){
    while(t--){
      Mem0(head),MemX(dis),top=0;
      scanf("%d%d%d",&n,&m,&w);
      while(m--){
        scanf("%d%d%d",&p1,&p2,&v);
        Addedge(p1,p2,v);
        Addedge(p2,p1,v);
      }
      while(w--){
        scanf("%d%d%d",&p1,&p2,&v);
        Addedge(p1,p2,-v);
      }
      if(spfa(1))puts("NO");
      else puts("YES");
    }
  }
}
