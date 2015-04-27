/*************************************************************************
     File Name: e.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月26日 星期日 21时33分28秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<vector>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define Mem0(x) memset(x,0,sizeof(x))
#define pb push_back
using namespace std;
const int N=100001,INF=0x3f3f3f3f;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[3*N];
int dfn[N],low[N],st[N],ed[N],belong[N],money[N],s_money[N],ti,top,st_top,s_cnt,n,max_m,k;
bool in_st[N];
vector<int> v[N];

inline void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

inline void Tarjan(int from){
  dfn[from]=low[from]=++ti;
  st[++st_top]=from;
  in_st[from]=1;
  int to;
  for(Edge *p=head[from];p;p=p->next){
    to=p->to;
    if(!dfn[to]){
      Tarjan(to);
      low[from]=Min(low[from],low[to]);
    }else if(in_st[to])
      low[from]=Min(low[from],dfn[to]);
  }
  if(low[from]==dfn[from]){
    s_cnt++;
    do{
      to=st[st_top];
      st[st_top--]=0;
      in_st[to]=0;
      belong[to]=s_cnt;
      s_money[s_cnt]+=money[to];
    }while(from!=to);
  }
}

inline void dfs(int i,int sum){
  sum+=s_money[i];
  for(int j=1;j<=k;++j)
    if(i==belong[ed[j]]){
      max_m=Max(max_m,sum);
      break;
    }
  //for(int j=1;j<=s_cnt;++j)
    //if(g[i][j])dfs(j,sum);
  for(int j=0;j<v[i].size();++j)dfs(v[i][j],sum);
}

int main(){
  int m,i,s,p1,p2;
  while(~scanf("%d%d",&n,&m)){
    for(i=1;i<=n;++i)v[i].clear();
    top=ti=st_top=s_cnt=0;
    Mem0(head)/*,Mem1(dp)*/,Mem0(dfn),Mem0(s_money);//Mem0(g);
    while(m--){
      scanf("%d%d",&p1,&p2);
      Addedge(p1,p2);
    }
    for(i=1;i<=n;++i)
      scanf("%d",money+i);
    scanf("%d",&s);
    scanf("%d",&k);
    for(i=1;i<=k;++i)
      scanf("%d",ed+i);
    for(i=1;i<=n;++i)
      if(!dfn[i])Tarjan(i);
    for(i=1;i<=n;++i)
      for(Edge *p=head[i];p;p=p->next)
        if(belong[i]!=belong[p->to])
          //g[belong[i]][belong[p->to]]=1;
          v[belong[i]].pb(belong[p->to]);
    max_m=0;
    dfs(belong[s],0);
    printf("%d\n",max_m);
  }
}
