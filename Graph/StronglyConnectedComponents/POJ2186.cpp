/*************************************************************************
     File Name: POJ2186.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月21日 星期二 17时27分13秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
using namespace std;
const int N=10010;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[5*N];
int dfn[N],low[N],st[N],belong[N],num[N];
int ti,top,st_top,s_cnt;
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
    }else if(in_st[from])
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
    }while(to!=from);
  }
}

int main(){
  int n,m,i,p1,p2,c1,c2;
  while(~scanf("%d%d",&n,&m)){
    Mem0(head),Mem0(dfn),Mem0(num);
    top=st_top=s_cnt=ti=c1=0;
    while(m--){
      scanf("%d%d",&p1,&p2);
      Addedge(p1,p2);
    }
    for(i=1;i<=n;++i)
      if(!dfn[i])Tarjan(i);
    for(i=1;i<=n;++i)
      for(Edge *p=head[i];p;p=p->next)
        if(belong[i]!=belong[p->to])
          out_de[belong[i]]=1;
    for(i=1;i<=s_cnt;++i)
      if(!out_de[i])c1++,c2=i;
    if(c1==1)printf("%d\n",num[c2]);
    else puts("0");
  }
}
