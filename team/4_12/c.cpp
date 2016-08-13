/*************************************************************************
     File Name: c.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月12日 星期日 16时26分17秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>
#include<bitset>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
using namespace std;
const int N=10005;
int in[N],sum[N],top,n;
struct Edge{
  int to;
  Edge* next;
}*head[N],e[N*2];

void Addedge(int from,int to){
  Edge* p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

void Top(){
  queue<int> q;
  int i,x,ans=0;
  for(i=1;i<=n;++i)if(!in[i])q.push(i);
  while(!q.empty()){
    x=q.front();
    q.pop();
    for(Edge* p=head[x];p;p=p->next){
      if(--in[p->to]==0)sum[p->to]=sum[x]+1,q.push(p->to);
    }
  }
  bool cycle=0;
  for(i=1;i<=n;++i)if(in[i])cycle=1;
  if(cycle)puts("-1");
  else{
    for(i=1;i<=n;++i)ans+=sum[i];
    printf("%d\n",ans);
  }
}

int main(){
  int m,i,p1,p2;
  while(~scanf("%d%d",&n,&m)){
    for(i=1;i<=n;++i)sum[i]=888;
    memset(head,0,sizeof head);
    memset(in,0,sizeof in);
    top=0;
    while(m--){
      scanf("%d%d",&p1,&p2);
      in[p1]++;
      Addedge(p2,p1);
    }
    Top();
  }
}
