/*************************************************************************
     File Name: POJ3140.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年09月12日 星期六 22时03分33秒
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
const int N=100010;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N*10];
int v[N],top;
ll dp[N],sum,min_diff;

void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

void dfs(int ch,int pre){
  dp[ch]=v[ch];
  for(Edge *p=head[ch];p;p=p->next)
    if(p->to!=pre)
      dfs(p->to,ch),dp[ch]+=dp[p->to];
}

void tree_dp(int ch,int pre){
  for(Edge *p=head[ch];p;p=p->next)
    if(p->to!=pre){
      tree_dp(p->to,ch);
      min_diff=Min(min_diff,Abs(sum,2*dp[p->to]));
    }
  min_diff=Min(min_diff,Abs(sum,2*dp[ch]));
}

int main(){
  int n,m,i,p1,p2,nc=0;
  while(~scanf("%d%d",&n,&m)&&(n||m)){
    sum=0,Mem0(head),min_diff=INF;
    for(i=1;i<=n;++i)
      scanf("%d",v+i),sum+=v[i];
    while(m--){
      scanf("%d%d",&p1,&p2);
      Addedge(p1,p2),Addedge(p2,p1);
    }
    dfs(1,-1),tree_dp(1,-1);
    printf("Case %d: %I64d\n",++nc,min_diff);
  }
}
