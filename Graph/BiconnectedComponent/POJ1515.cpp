/*************************************************************************
     File Name: POJ1515.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月14日 星期二 20时51分02秒
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
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
const int N=1010;
using namespace std;
int low[N],dfn[N],tim,top;
bool vis[N],vis_e[N*N/2];
struct Edge{
  int from,to,id;
  bool flag;
  Edge *next;
}*head[N],e[N*N];
stack<int> s;

void Addedge(int from,int to,int id){
  Edge *p=&e[++top];
  p->from=from,p->to=to,p->id=id;
  p->flag=0,p->next=head[from];
  head[from]=p;
}

void Tarjan_bcc(int from,int pre){
  dfn[from]=low[from]=++tim;
  s.push(from);
  int to,temp;
  for(Edge *p=head[from];p;p=p->next){
    to=p->to;
    if(to==pre)continue;
    if(!dfn[to]){
      Tarjan_bcc(to,from);
      low[from]=Min(low[from],low[to]);
      if(dfn[from]<low[to]){
        p->flag=1;
        do{
          temp=s.top();
          s.pop();
        }while(temp!=to);
      }
    }else low[from]=Min(low[from],dfn[to]);
  }
}

void dfs(int from){
  vis[from]=1;
  for(Edge *p=head[from];p;p=p->next){
    int to=p->to,id=p->id;
    if(!vis_e[id]){
      vis_e[id]=1;
      printf("%d %d\n",from,to);
      if(p->flag)printf("%d %d\n",to,from);
      if(!vis[to])dfs(to);
    }
  }
}

void init(){
  Mem0(head),Mem0(dfn),Mem0(low),Mem0(vis),Mem0(vis_e);
  while(!s.empty())s.pop();
  top=tim=0;
}

int main(){
  int n,m,p1,p2,i,nc(0);
  while(~scanf("%d%d",&n,&m)&&(n||m)){
    init();
    printf("%d\n\n",++nc);
    for(i=1;i<=m;++i){
      scanf("%d%d",&p1,&p2);
      Addedge(p1,p2,i);
      Addedge(p2,p1,i);
    }
    for(i=1;i<=n;++i)
      if(!dfn[i])Tarjan_bcc(i,-1);
    for(i=1;i<=n;++i)if(!vis[i])dfs(i);
    puts("#");
  }
}
