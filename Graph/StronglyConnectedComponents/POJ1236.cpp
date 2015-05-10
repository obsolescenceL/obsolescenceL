/*************************************************************************
     File Name: POJ1236.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月05日 星期二 21时15分46秒
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
const int N=110;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N*N];
int dfn[N],low[N],st[N],belong[N],ti,top,st_top,s_cnt;
bool in_st[N],in_de[N],out_de[N];

inline void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

inline void Tarjan(int from){
  dfn[from]=low[from]=++ti;
  in_st[from]=1,st[++st_top]=from;
  int to;
  for(Edge *p=head[from];p;p=p->next){
    to=p->to;
    if(!dfn[to]){
      Tarjan(to);
      low[from]=Min(low[from],low[to]);
    }else if(in_st[to])low[from]=Min(low[from],dfn[to]);
  }
  if(dfn[from]==low[from]){
    s_cnt++;
    do{
      to=st[st_top];
      st[st_top--]=0;
      in_st[to]=0;
      belong[to]=s_cnt;
    }while(to!=from);
  }
}

int main(){
  int n,i,p1,p2;
  while(~scanf("%d",&n)){
    Mem0(head),Mem0(dfn),Mem0(out_de),Mem0(in_de);
    top=ti=st_top=s_cnt=0;
    for(i=1;i<=n;++i){
      p1=i;
      while(scanf("%d",&p2),p2)
        Addedge(p1,p2);
    }
    for(i=1;i<=n;++i)
      if(!dfn[i])Tarjan(i);
    if(s_cnt==1){
      puts("1\n0");
      continue;
    }
    for(i=1;i<=n;++i)
      for(Edge *p=head[i];p;p=p->next)
        if(belong[i]!=belong[p->to]){
          out_de[belong[i]]=1;
          in_de[belong[p->to]]=1;
        }
    int cnt_o=0,cnt_i=0;
    for(i=1;i<=s_cnt;++i){
      if(!out_de[i])cnt_o++;
      if(!in_de[i])cnt_i++;
    }
    printf("%d\n%d\n",cnt_i,Max(cnt_o,cnt_i));
  }
}

