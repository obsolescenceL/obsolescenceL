/*************************************************************************
     File Name: POJ2942.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月20日 星期一 08时36分25秒
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
const int N=1010,M=1000010;
int low[N],dfn[N],color[N],odd[N],belong[N],temp[N],top,tim,bcc_n,cnt,ans;
bool g[N][N];
stack<int> s;
struct Edge{
  int from,to;
  bool vis;
  Edge *next;
}*head[N],e[M<<1];

void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->from=from,p->to=to,p->vis=0;
  p->next=head[from],head[from]=p;
}

bool odd_cycle(int from,int clr){
  color[from]=clr;
  for(Edge *p=head[from];p;p=p->next){
    int to=p->to;
    if(belong[to]==bcc_n){
      if(color[to] && color[to]==color[from])return 1;
      if(!color[to] && odd_cycle(to,-clr))return 1;
    }
  }
  return 0;
}

void Tarjan(int from,int pre){
  dfn[from]=low[from]=++tim;
  s.push(from);
  int to,x;
  for(Edge *p=head[from];p;p=p->next){
    int to=p->to;
    if(to==pre)continue;
    if(!dfn[to]){
      Tarjan(to,from);
      low[from]=Min(low[from],low[to]);
      if(dfn[from]<=low[to]){
        bcc_n++;
        do{
          x=s.top();
          s.pop();
          belong[x]=bcc_n;
          temp[++cnt]=x;
        }while(x!=to);
        temp[++cnt]=from;
        Mem0(color);
        if(cnt>=3 && odd_cycle(from,1))
          while(cnt)
            odd[temp[cnt--]]=1;
        else cnt=0;
      }
    }else low[from]=Min(low[from],dfn[to]);
  }
}

void init(){
  Mem0(head),Mem0(dfn),Mem0(low);
  Mem0(g),Mem0(odd),Mem0(belong);
  while(!s.empty())s.pop();
  ans=top=tim=bcc_n=cnt=0;
}

int main(){
  int n,m,i,j,p1,p2;
  while(~scanf("%d%d",&n,&m)&&(n||m)){
    init();
    for(i=1;i<=m;++i){
      scanf("%d%d",&p1,&p2);
      g[p1][p2]=g[p2][p1]=1;
    }
    for(i=1;i<=n;++i)
      for(j=i+1;j<=n;++j)
        if(!g[i][j]){
          Addedge(i,j);
          Addedge(j,i);
        }
    for(i=1;i<=n;++i)
      if(!dfn[i])Tarjan(i,-1);
    for(i=1;i<=n;++i)
      if(!odd[i])ans++;
    printf("%d\n",ans);
  }
}
