/*************************************************************************
     File Name: HDU2242.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月13日 星期一 10时33分16秒
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
const int N=10010,M=20010,INF=0x3f3f3f3f;
int low[N],dfn[N],num[N],tim,bc_n,sum,ans,top;
stack<int> s;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[M<<1];

void Addedge(int from,int to){
  Edge *p=&e[top++];
  p->to=to,p->next=head[from],head[from]=p;
}

void Tarjan_bc(int from,int pre){
  dfn[from]=low[from]=++tim;
  s.push(from);
  int to,tmp,x,flag=1;
  for(Edge *p=head[from];p;p=p->next){
    to=p->to;
    if(to==pre&&flag){
      flag=0;
      continue;
    }
    if(!dfn[to]){
      Tarjan_bc(to,from);
      low[from]=Min(low[from],low[to]);
      if(dfn[from]<low[to]){
        bc_n++;
        tmp=0;
        do{
          x=s.top();
          s.pop();
          tmp+=num[x];
        }while(x!=to);
        ans=Min(ans,Abs(sum,tmp<<1));
        num[from]+=tmp;
      }
    }else low[from]=Min(low[from],dfn[to]);
  }
}

void init(){
  Mem0(head),Mem0(dfn),Mem0(low);
  while(!s.empty())s.pop();
  bc_n=sum=tim=top=0;
  ans=INF;
}


int main(){
  int p1,p2,n,m,i;
  while(~scanf("%d%d",&n,&m)){
    init();
    for(i=0;i<n;++i)scanf("%d",num+i),sum+=num[i];
    while(m--){
      scanf("%d%d",&p1,&p2);
      Addedge(p1,p2);
      Addedge(p2,p1);
    }
    for(i=0;i<n;++i)
      if(!dfn[i])Tarjan_bc(i,-1);
    if(!bc_n)puts("impossible");
    else printf("%d\n",ans);
  }
}
