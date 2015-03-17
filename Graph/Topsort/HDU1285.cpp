/*************************************************************************
    > File Name: HDU1285.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月11日 19:17:57
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=505;
int indegree[MAXN],visit[MAXN];
int n,m,p1,p2,top;
struct Edge{
  int to;
  Edge*next;
}*head[MAXN],e[MAXN];
struct cmp{
  bool operator ()(int x,int y){
    return x>y;
  }
};
vector<int>order;

void Addedge(int from ,int to){
  Edge*p=&e[top++];
  p->to=to,p->next=head[from],head[from]=p;
}

void Topsort(){
  int cnt=0;
  priority_queue<int,vector<int>,cmp>q;
  for(int i=1;i<=n;i++)
    if(!indegree[i])q.push(i);
  while(!q.empty()){
    int a=q.top();
    q.pop();
    order.push_back(a);
    //printf("%d ",a);
    for(Edge*p=head[a];p;p=p->next){
      indegree[p->to]--;
      if(!indegree[p->to])q.push(p->to);
    }
  }
  for(int i=0;i<order.size();i++)
    i==n-1? printf("%d\n",order[i]) : printf("%d ",order[i]);
}

int main(){
  while(~scanf("%d%d",&n,&m)){
    order.clear();
    memset(indegree,0,sizeof indegree);
    memset(head,0,sizeof head);
    top=0;
    while(m--){
      scanf("%d%d",&p1,&p2);
      indegree[p2]++;
      Addedge(p1,p2);
    }
    //for(int i=1;i<=n;i++)printf("indegree[%d]=%d ",i,indegree[i]);puts("");
    Topsort();
  }
}
