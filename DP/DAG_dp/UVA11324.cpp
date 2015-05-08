/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月26日 星期日 15时28分32秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define Mem0(x) memset(x,0,sizeof(x))
const int N=1001;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N*50];
int dfn[N],low[N],st[N],belong[N],num[N],dp[N],s_cnt,ti,top,st_top;
bool in_st[N],g[N][N],in_de[N];

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
  if(dfn[from]==low[from]){
    s_cnt++;
    do{
      to=st[st_top];
      st[st_top--]=0;
      in_st[to]=0;
      belong[to]=s_cnt;
      num[s_cnt]++;
    }while(from!=to);
  }
}

inline int dfs(int i){
  int &ans=dp[i];
  if(ans)return ans;
  ans=num[i];
  for(int j=1;j<=s_cnt;++j)
    if(g[i][j])ans=Max(ans,dfs(j)+num[i]);
  return ans;
}

int main(){
  int t,n,m,i,p1,p2,max_n;
  while(~scanf("%d",&t)){
    while(t--){
      Mem0(dfn),Mem0(head),Mem0(num),Mem0(dp),Mem0(g),Mem0(in_de);
      ti=top=st_top=s_cnt=max_n=0;
      scanf("%d%d",&n,&m);
      while(m--){
        scanf("%d%d",&p1,&p2);
        Addedge(p1,p2);
      }
      for(i=1;i<=n;++i)
        if(!dfn[i])Tarjan(i);
      for(i=1;i<=n;++i)
        for(Edge *p=head[i];p;p=p->next)
          if(belong[i]!=belong[p->to]){
            g[belong[i]][belong[p->to]]=1;
            in_de[belong[p->to]]=1;
          }
      for(i=1;i<=s_cnt;++i)
        if(!in_de[i])
          max_n=Max(max_n,dfs(i));
      printf("%d\n",max_n);
    }
  }
}
