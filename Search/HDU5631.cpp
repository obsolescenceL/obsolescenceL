/*************************************************************************
     File Name: HDU5631.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年02月24日 星期三 16时26分52秒
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
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=110;
struct Edge{
  int p1,p2;
}e[N];
struct edge{
  int to;
  edge *next;
}*head[N],ed[N*2];
int top;
bool vis[N];

void Addedge(int from,int to){
  edge *p=&ed[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

void dfs(int x){
  for(edge *p=head[x];p;p=p->next)
    if(!vis[p->to]){
      vis[p->to]=1;
      dfs(p->to);
    }
}

int main(){
  int t,n,i,j,k,ans,flag;
  while(~scanf("%d",&t)){
    while(t--){
      ans=0;
      scanf("%d",&n);
      for(i=0;i<=n;++i)
        scanf("%d%d",&e[i].p1,&e[i].p2);
      for(i=0;i<=n;++i)
        for(j=i;j<=n;++j){
          Mem0(head),top=0,flag=1;
          for(k=0;k<=n;++k){
            if(k==i || k==j)continue;
            Addedge(e[k].p1,e[k].p2);
            Addedge(e[k].p2,e[k].p1);
          }
          Mem0(vis);
          vis[1]=1;
          dfs(1);
          for(k=1;k<=n;++k)
            if(!vis[k])flag=0;
          if(flag)ans++;
        }
      printf("%d\n",ans);
    }
  }
}
