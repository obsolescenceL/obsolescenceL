/*************************************************************************
    > File Name: HDU3342.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月13日  9:16:30
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=110;
struct Edge{
  int to;
  Edge* next;
}*head[MAXN],e[MAXN];
int indegree[MAXN];
int n,m,top,cnt,p1,p2;

void Addedge(int from,int to){
  Edge* p=&e[top++];
  p->to=to,p->next=head[from],head[from]=p;
}

void Topsort(){
  queue<int> q;
  for(int i=0;i<n;i++)if(!indegree[i])q.push(i);
  while(!q.empty()){
    int x=q.front();
    q.pop();
    cnt--;
    for(Edge* p=head[x];p;p=p->next)
      if(--indegree[p->to]==0)q.push(p->to);
  }
  if(cnt)puts("NO");
  else puts("YES");
}

int main(){
  while(scanf("%d%d",&n,&m),n||m){
    memset(head,0,sizeof head);
    memset(indegree,0,sizeof indegree);
    cnt=n,top=0;
    while(m--){
      scanf("%d%d",&p1,&p2);
      indegree[p2]++;
      Addedge(p1,p2);
    }
    Topsort();
  }
}
