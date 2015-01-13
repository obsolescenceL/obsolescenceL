/*************************************************************************
    > File Name: HDU1811.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月13日 10:13:42
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=10010;
typedef int array[MAXN];
typedef int array2[MAXN*2];
array indegree,fa;
array2 num,a,b;
int cnt,top,n,m;
char op[MAXN*2][5];
struct Edge{
  int to;
  Edge* next;
}*head[MAXN],e[MAXN*2];

void Addedge(int from,int to){
  Edge* p=&e[top++];
  p->to=to,p->next=head[from],head[from]=p;
}

int find(int x){
  return x==fa[x]? x:fa[x]=find(fa[x]);
}

void Union(int x,int y){
  int fx=find(x),fy=find(y);
  if(fx!=fy)fa[fy]=fx,cnt--;
}

void Topsort(){
  int k=0,flag=0;
  queue<int> q;
  for(int i=0;i<n;i++)
    if(!indegree[find(i)]&&i==find(i)){
      num[k]++;
      q.push(i);
    }
  //printf("num[%d]=%d\n",k,num[k]);
  k++;
  while(!q.empty()){
    int x=q.front();
    q.pop();
    cnt--;
    for(Edge*p=head[x];p;p=p->next)
      if(--indegree[p->to]==0)num[k]++,q.push(p->to);
    k++;
  }
  //printf("cnt=%d\n",cnt);
  for(int i=0;i<n;i++)if(num[i]>1)flag=1;
  if(cnt)puts("CONFLICT");
  else if(flag)puts("UNCERTAIN");
  else puts("OK");
}

int main(){
  while(~scanf("%d%d",&n,&m)){
    memset(head,0,sizeof head);
    memset(indegree,0,sizeof indegree);
    memset(num,0,sizeof num);
    for(int i=0;i<n;i++)fa[i]=i;
    top=0,cnt=n;
    for(int i=0;i<m;i++){
      scanf("%d%s%d",&a[i],op[i],&b[i]);
      if(op[i][0]=='=') Union(a[i],b[i]);
    }
    for(int i=0;i<m;i++){
      if(op[i][0]=='>')Addedge(find(a[i]),find(b[i])),indegree[find(b[i])]++;
      else if(op[i][0]=='<')Addedge(find(b[i]),find(a[i])),indegree[find(a[i])]++;
    }
    Topsort();
  }
}
