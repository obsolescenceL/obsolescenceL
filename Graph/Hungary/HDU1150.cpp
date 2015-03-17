/*************************************************************************
    > File Name: HDU1150.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月10日 11:04:39
 ************************************************************************/
#include<cstdio>
#include<cstring>
const int MAXN=1005;
typedef int array[MAXN];
array my,visit_y;
int a,b,c,nx,ny,k,top;
struct Edge{
  int to;
  Edge* next;
}*head[MAXN],e[MAXN];

void Addedge(int from,int to){
  Edge*p=&e[top++];
  p->to=to,p->next=head[from],head[from]=p;
}

bool DFS(int x){
  for(Edge*p=head[x];p;p=p->next){
    if(!visit_y[p->to]){
      visit_y[p->to]=1;
      if(!my[p->to] || DFS(my[p->to])){
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
  for(int x=1;x<=nx;x++){
    memset(visit_y,0,sizeof visit_y);
    if(DFS(x))cnt++;
  }
  printf("%d\n",cnt);
}

int main(){
  while(scanf("%d%d%d",&nx,&ny,&k),nx){
    top=0;
    memset(head,0,sizeof head);
    while(k--){
      scanf("%d%d%d",&a,&b,&c);
      Addedge(b,c);
    }
    Hungary();
  }
}

