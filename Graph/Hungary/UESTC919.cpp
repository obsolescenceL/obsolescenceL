/*************************************************************************
     File Name: UESTC919.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月04日 星期一 21时58分42秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define pb push_back
const int N=1001;
int my[N],vy[N];
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N*N];
int nx,ny,p1,p2,top,k;

inline void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

inline bool Dfs(int x){
  for(Edge *p=head[x];p;p=p->next){
    if(vy[p->to])continue;
    vy[p->to]=1;
    if(!my[p->to] || Dfs(my[p->to])){
      my[p->to]=x;
      return 1;
    }
  }
  return 0;
}

inline void Hungary(){
  Mem0(my);
  int cnt=0;
  for(int x=1;x<=nx;++x){
    Mem0(vy);
    if(Dfs(x))cnt++;
  }
  printf("%d\n",cnt);
}

int main(){
  while(~scanf("%d%d%d",&nx,&ny,&k)){
    top=0;Mem0(head);
    while(k--){
      scanf("%d%d",&p1,&p2);
      Addedge(p1,p2);
    }
    Hungary();
  }
}
