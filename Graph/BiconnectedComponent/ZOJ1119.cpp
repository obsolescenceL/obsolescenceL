/*************************************************************************
     File Name: ZOJ1119.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月14日 星期二 21时51分02秒
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
const int N=1010;
int low[N],dfn[N],cnt[N],tim,top,n;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N*N];
stack<int> s;

void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

void Tarjan_bcc(int from,int pre){
  dfn[from]=low[from]=++tim;
  s.push(from);
  int to,x;
  for(Edge *p=head[from];p;p=p->next){
    to=p->to;
    if(to==pre)continue;
    if(!dfn[to]){
      Tarjan_bcc(to,from);
      low[from]=Min(low[from],low[to]);
      if(dfn[from]<=low[to]){
        do{
          x=s.top(),s.pop();
          cnt[x]++;
        }while(x!=to);
        cnt[from]++;
        //cout<<"from="<<from<<endl;
        //cout<<"cnt_out="<<cnt_out<<" n="<<n<<endl;
      }
    }else low[from]=Min(low[from],dfn[to]);
  }
}

void init(){
  Mem0(head),Mem0(dfn),Mem0(low),Mem0(cnt);
  while(!s.empty())s.pop();
  tim=top=n=0;
}

int main(){
  int p1,p2,i,nc=0;
  while(~scanf("%d",&p1)&&p1){
    init();
    scanf("%d",&p2);
    Addedge(p1,p2);
    Addedge(p2,p1);
    n=Max(n,Max(p1,p2));
    while(scanf("%d",&p1)&&p1){
      scanf("%d",&p2);
      Addedge(p1,p2);
      Addedge(p2,p1);
      n=Max(n,Max(p1,p2));
    }
    for(i=1;i<=n;++i)
      if(!dfn[i])Tarjan_bcc(i,-1);
    if(nc)puts("");
    printf("Network #%d\n",++nc);
    bool is_have=1;
    for(i=1;i<=n;++i)
      if(cnt[i]>1)
        printf("  SPF node %d leaves %d subnets\n",i,cnt[i]),is_have=0;
    if(is_have)puts("  No SPF nodes");
  }
}
