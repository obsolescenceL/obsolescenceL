/*************************************************************************
     File Name: HDU1269.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月21日 星期二 16时37分32秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define Mem0(x) memset(x,0,sizeof(x))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
const int N=10001;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[10*N];
int dfn[N],low[N],st[N],ti,s_cnt,top,s_top;
bool inst[N];

inline void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

inline void Tarjan(int from){
  dfn[from]=low[from]=++ti;
  st[++s_top]=from;
  inst[from]=1;
  int to;
  for(Edge *p=head[from];p;p=p->next){
    to=p->to;
    if(!dfn[to]){
      Tarjan(to);
      low[from]=Min(low[from],low[to]);
    }else if(inst[to])
      low[from]=Min(low[from],dfn[to]);
  }
  if(dfn[from]==low[from]){
    do{
      to=st[s_top];
      st[s_top--]=0;
      inst[to]=0;
    }while(to!=from);
    s_cnt++;
  }
}

int main(){
  int n,m,i,p1,p2;
  while(~scanf("%d%d",&n,&m)&&(n||m)){
    Mem0(dfn),Mem0(head);
    ti=top=s_top=s_cnt=0;
    while(m--){
      scanf("%d%d",&p1,&p2);
      Addedge(p1,p2);
    }
    for(i=1;i<=n;++i)
      if(!dfn[i])Tarjan(i);
    if(s_cnt==1)puts("Yes");
    else puts("No");
  }
}
