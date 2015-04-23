/*************************************************************************
     File Name: HDU1827.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月23日 星期四 16时16分50秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define Min(x,y) ((x)<(y)?(x):(y))
#define Mem0(x) memset(x,0,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
const int N=1001;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[2*N];
int dfn[N],low[N],st[N],c[N],belong[N],min_c[N],ti,top,st_top,s_cnt;
bool in_st[N],out_de[N];

inline void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

inline void Tarjan(int from){
  dfn[from]=low[from]=++ti;
  in_st[from]=1;
  st[++st_top]=from;
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
      min_c[s_cnt]=Min(min_c[s_cnt],c[to]);
    }while(to!=from);
  }
}

int main(){
  int n,m,p1,p2,i,cnt,ans;
  while(~scanf("%d%d",&n,&m)){
    Mem0(head),Mem0(dfn),Mem0(out_de),MemX(min_c);
    ti=top=st_top=s_cnt=cnt=ans=0;
    for(i=1;i<=n;++i)scanf("%d",c+i);
    while(m--){
      scanf("%d%d",&p1,&p2);
      Addedge(p1,p2);
    }
    for(i=1;i<=n;++i)
      if(!dfn[i])Tarjan(i);
    for(i=1;i<=n;++i)
      for(Edge *p=head[i];p;p=p->next)
        if(belong[i]!=belong[p->to])
          out_de[belong[p->to]]=1;
    for(i=1;i<=s_cnt;++i)
      if(!out_de[i])cnt++,ans+=min_c[i];
    printf("%d %d\n",cnt,ans);
  }
}
