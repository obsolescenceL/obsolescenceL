/*************************************************************************
     File Name: UVALive2664.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月18日 星期六 21时54分19秒
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
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=2010;
int low[N],dfn[N],tim,top;
bool vis[N],vis_e[N*N/2];
struct Edge{
  int from,to,id;
  bool flag,type;
  Edge *next;
}*head[N],e[N*N/2];

void Addedge(int from,int to,int id,bool type){
  Edge *p=&e[++top];
  p->from=from,p->to=to,p->id=id;
  p->flag=0,p->type=type,p->next=head[from];
  head[from]=p;
}

void Tarjan_bcc(int from,int pre){
  dfn[from]=low[from]=++tim;
  int to;
  for(Edge *p=head[from];p;p=p->next){
    to=p->to;
    if(to==pre)continue;
    if(!dfn[to]){
      Tarjan_bcc(to,from);
      low[from]=Min(low[from],low[to]);
      if(dfn[from]<low[to])
        p->flag=1;
    }else low[from]=Min(low[from],dfn[to]);
  }
}

void dfs(int from){
  vis[from]=1;
  for(Edge *p=head[from];p;p=p->next){
    int to=p->to,id=p->id;
    if(!vis_e[id]){
      vis_e[id]=1;
      if(p->type){
        if(p->flag)printf("%d %d 2\n",from,to);
        else printf("%d %d 1\n",from,to);
      }
      if(!vis[to])dfs(to);
    }
  }
}

void init(){
  Mem0(head),Mem0(dfn),Mem0(low),Mem0(vis),Mem0(vis_e);
  top=tim=0;
}

int main(){
  int n,m,p1,p2,type,i;
  while(~scanf("%d%d",&n,&m)){
    for(i=1;i<=m;++i){
      scanf("%d%d%d",&p1,&p2,&type);
      if(type-1)Addedge(p1,p2,i,1),Addedge(p2,p1,i,1);
      else Addedge(p1,p2,i,0);
    }
    for(i=1;i<=n;++i)if(!dfn[i])Tarjan_bcc(i,-1);
    for(i=1;i<=n;++i)if(!vis[i])dfs(i);
  }
}
