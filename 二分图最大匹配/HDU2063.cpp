/*************************************************************************
    > File Name: HDU2063.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月10日  9:16:55
 ************************************************************************/
#include<cstdio>
#include<cstring>
const int MAXN=510;
typedef int array[MAXN];
array my,vy; 
int k,nx,ny,a,b,top;
struct Edge{
  int to;
  Edge* next;
}*head[MAXN],e[1010];
void Addedge(int from,int to){
  Edge* p=&e[top++];
  p->to=to,p->next=head[from],head[from]=p;
}
bool DFS(int x){
  for(Edge* p=head[x];p;p=p->next){
    if(!vy[p->to]){
      vy[p->to]=1;
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
    memset(vy,0,sizeof vy);
    if(DFS(x))cnt++;
  }
  printf("%d\n",cnt);
}
int main(){
  while(scanf("%d",&k),k){
    top=0;
    memset(head,0,sizeof head);
    scanf("%d%d",&nx,&ny);
    for(int i=1;i<=k;i++){
      scanf("%d%d",&a,&b);
      Addedge(a,b);
    }
    Hungary();
  }
}
