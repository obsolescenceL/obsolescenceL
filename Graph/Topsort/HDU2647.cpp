/*************************************************************************
    > File Name: HDU2647.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月12日 15:10:22
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=10005;
int indegree[MAXN],sum[MAXN];
int n,m,top,cycle,p1,p2,s;
struct Edge{
  int to;
  Edge* next;
}*head[MAXN],e[MAXN*2];

void Addedge(int from,int to){
  Edge* p=&e[top++];
  p->to=to,p->next=head[from],head[from]=p;
}

void Topsort(){
  queue<int> q;
  for(int i=1;i<=n;i++)if(!indegree[i])q.push(i);
  while(!q.empty()){
    int x=q.front();
    q.pop();
    for(Edge* p=head[x];p;p=p->next){
      indegree[p->to]--;
      if(!indegree[p->to])sum[p->to]=sum[x]+1,q.push(p->to);
    }
  }
  for(int i=1;i<=n;i++)if(indegree[i])cycle=1;
  if(cycle)puts("-1");
  else{
    for(int i=1;i<=n;i++)s+=sum[i];
    printf("%d\n",s);
  }
}

int main(){
  while(~scanf("%d%d",&n,&m)){
    for(int i=1;i<=n;i++)sum[i]=888;
    memset(head,0,sizeof head);
    memset(indegree,0,sizeof indegree);
    top=cycle=s=0;
    while(m--){
      scanf("%d%d",&p1,&p2);
      indegree[p1]++;
      Addedge(p2,p1);
    }
    Topsort();
  }
}
