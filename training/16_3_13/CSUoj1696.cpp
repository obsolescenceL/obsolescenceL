/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五  3/18 15:59:09 2016
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Mem0(x) memset(x,0,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
using namespace std;
const int N=210;
struct Edge{
  int to,d,v;
  Edge *next;
}*head[N],e[N*N];
bool vis[N];
int top,dis[N];
double dgr[N];

void Addedge(int from,int to,int d,int v){
  Edge *p=&e[++top];
  p->to=to,p->d=d,p->v=v,p->next=head[from],head[from]=p;
}

void spfa(){
  MemX(dis),Mem0(vis);
  queue<int> q;
  dis[1]=0;
  dgr[1]=0.0;
  q.push(1);
  vis[1]=1;
  int x,to;
  while(!q.empty()){
    x=q.front(),q.pop();
    vis[x]=0;
    for(Edge *p=head[x];p;p=p->next){
      to=p->to;
      if(dis[to]>dis[x]+p->d){
        dis[to]=dis[x]+p->d;
        dgr[to]=dgr[x]+p->v;
        if(!vis[to]){
          vis[to]=1;
          q.push(to);
        }
      }
    }
  }
}

int main(){
  int n,m,p,i,s,t,d,v;
  while(~scanf("%d%d%d",&n,&m,&p)){
    top=0,Mem0(head);
    for(i=0;i<m;++i){
      scanf("%d%d%d%d",&s,&t,&d,&v);
      Addedge(s,t,d,v);
      Addedge(t,s,d,v);
    }
    spfa();
    double ans=0,tmp;
    int pp;
    for(i=1;i<=n;++i){
      if(p<dis[i]*2)continue;
      tmp=dgr[i]*2;
      pp=p-dis[i]*2;
      //cout<<"dis["<<i<<"]="<<dis[i]<<endl;
      //cout<<"pp="<<pp<<endl;
      if(pp%2)pp--;
      for(Edge *x=head[i];x;x=x->next)
        tmp=Max(tmp,dgr[i]*2+(double)pp*x->v/x->d);
      ans=Max(ans,tmp);
    }
    printf("%f\n",ans);
  }
}
