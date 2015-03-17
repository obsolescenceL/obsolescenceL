/*************************************************************************
     File Name: e.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月14日 星期六 10时02分54秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int M=30010;

struct Edge{
  int to;
  Edge* next;
}*head[M],e[100010];
int inde[M],top,n,v[M];

void Addedge(int from,int to){
  Edge* p=&e[top++];
  p->to=to,p->next=head[from],head[from]=p;
}

void Top(){
  priority_queue<int> q;
  int i,k=0;
  for(i=1;i<=n;++i)if(!inde[i])q.push(i);
  while(!q.empty()){
    int x=q.top();
    q.pop();
    v[k++]=x;
    for(Edge* p=head[x];p;p=p->next)
      if(--inde[p->to]==0)q.push(p->to);
  }
  for(i=n-1;i>=0;--i)
    i?printf("%d ",v[i]):printf("%d\n",v[i]);
}

int main(){
  int t,m,p1,p2;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d",&n,&m);
      memset(inde,0,sizeof inde);
      memset(head,0,sizeof head);
      top=0;
      while(m--){
        scanf("%d%d",&p1,&p2);
        inde[p1]++;
        Addedge(p2,p1);
      }
      Top();
    }
  }
}
