/*************************************************************************
    > File Name: POJ2536.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月10日 17:26:28
 ************************************************************************/
#include<cstdio>
#include<cmath>
#include<cstring>
const int MAXN=105;
typedef int array[MAXN];
typedef double arrdo[MAXN];
array visit_m,mm;
arrdo nx,ny,mx,my;
int n,m,s,v,top;
double d;
struct Edge{
  int to;
  Edge* next;
}*head[MAXN],e[MAXN*MAXN];

void Addedge(int from,int to){
  Edge* p=&e[top++];
  p->to=to,p->next=head[from],head[from]=p;
}

bool DFS(int x){
  for(Edge*p=head[x];p;p=p->next){
    if(!visit_m[p->to]){
      visit_m[p->to]=1;
      if(!mm[p->to] || DFS(mm[p->to])){
        mm[p->to]=x;
        return 1;
      }
    }
  }
  return 0;
}

void Hungary(){
  memset(mm,0,sizeof mm);
  int cnt=0;
  for(int x=1;x<=n;x++){
    memset(visit_m,0,sizeof visit_m);
    if(DFS(x))cnt++;
  }
  printf("%d\n",n-cnt);
}

int main(){
  while(~scanf("%d%d%d%d",&n,&m,&s,&v)){
    top=0;
    memset(head,0,sizeof head);
    for(int i=1;i<=n;i++)scanf("%lf%lf",nx+i,ny+i);
    for(int i=1;i<=m;i++)scanf("%lf%lf",mx+i,my+i);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++){
        d=sqrt(pow(nx[i]-mx[j],2)+pow(ny[i]-my[j],2));
        //printf("d/v=%.1lf\n",d/v);
        if(d/v<=s)Addedge(i,j);
      }
    Hungary();
  }
}
