/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月18日 星期三 18时47分01秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
int my[1000];
bool vy[1000];
int n,top;
struct Edge{
  int to;
  Edge* next;
}*head[1000],e[10000];

void Addedge(int from,int to){
  Edge* p=&e[top++];
  p->to=to,p->next=head[from],head[from]=p;
}

bool DFS(int x){
  for(Edge* p=head[x];p;p=p->next){
    if(!vy[p->to]){
      vy[p->to]=1;
      if(!my[p->to]||DFS(my[p->to])){
        my[p->to]=x;
        return 1;
      }
    }
  }
  return 0;
}

void Hungary(){
  memset(my,0,sizeof my);
  int cnt=0;
  for(int x=0;x<n;++x){
    memset(vy,0,sizeof vy);
    if(DFS(x))cnt++;
  }
  printf("%d\n",n-(cnt+1)/2);
}

int main(){
  int i,a,b,m;
  while(~scanf("%d",&n)){
    top=0;
    memset(head,0,sizeof head);
    for(i=0;i<n;++i){
      scanf("%d: (%d)",&a,&m);
      while(m--){
        scanf("%d",&b);
        Addedge(a,b);
      }
    }
    Hungary();
  }
}
