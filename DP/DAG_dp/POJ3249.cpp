/*************************************************************************
     File Name: POJ3249.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月08日 星期五 11时26分01秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Mem0(x) memset(x,0,sizeof(x))
const int N=100001,INF=0x3f3f3f3f;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N*10];
int v[N],top,dp[N],out_de[N],in_de[N],vis[N];

void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

int dfs(int i){
  if(vis[i])return dp[i];
  vis[i]=1;
  int& ans=dp[i]=-INF;
  for(Edge *p=head[i];p;p=p->next)
    ans=Max(ans,dfs(p->to));
  if(in_de[i])ans+=v[i];
  else ans=v[i];
  return ans;
}

int main(){
  int n,m,i,p1,p2;
  while(~scanf("%d%d",&n,&m)){
    top=0;
    Mem0(head),Mem0(vis),Mem0(out_de),Mem0(in_de);
    for(i=1;i<=n;++i)scanf("%d",v+i);
    while(m--){
      scanf("%d%d",&p1,&p2);
      Addedge(p2,p1);
      out_de[p1]++;
      in_de[p2]++;
    }
    int max_v=-INF;
    for(i=1;i<=n;++i)
      if(!out_de[i])
        max_v=Max(max_v,dfs(i));
    printf("%d\n",max_v);
  }
}
