/*************************************************************************
     File Name: HDU3394.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月14日 星期二 10时07分39秒
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
const int N=10010,M=100010;
int low[N],dfn[N],num[N],tim,top,ans1,ans2,cnt_p,block[N];
bool flag[N];
struct Edge{
  int to;
  Edge *next;
}*head[N],e[M<<1];
stack<int> s;

void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

void Tarjan_bcc(int from,int pre){
  dfn[from]=low[from]=++tim;
  s.push(from);
  int to,x,edge_s,i;
  for(Edge *p=head[from];p;p=p->next){
    to=p->to;
    if(to==pre)continue;
    if(!dfn[to]){
      Tarjan_bcc(to,from);
      low[from]=Min(low[from],low[to]);
      if(dfn[from]<=low[to]){
        if(dfn[from]<low[to])ans1++;
        cnt_p=edge_s=0;
        Mem0(flag);
        do{
          x=s.top(),s.pop();
          block[++cnt_p]=x,flag[x]=1;
        }while(to!=x);
        block[++cnt_p]=from,flag[from]=1;
        for(i=1;i<=cnt_p;++i)
          for(Edge *pp=head[block[i]];pp;pp=pp->next)
            if(flag[pp->to])edge_s++;
        edge_s>>=1;
        if(cnt_p<edge_s)ans2+=edge_s;
      }
    }else low[from]=Min(low[from],dfn[to]);
  }
}

void init(){
  Mem0(head),Mem0(dfn),Mem0(low);
  while(!s.empty())s.pop();
  tim=top=ans1=ans2=0;
}

int main(){
  int n,m,i,p1,p2;
  while(~scanf("%d%d",&n,&m)&&(n||m)){
    init();
    while(m--){
      scanf("%d%d",&p1,&p2);
      //cout<<"p1="<<p1<<" p2="<<p2<<endl;
      Addedge(p1,p2);
      Addedge(p2,p1);
    }
    for(i=0;i<n;++i)
      if(!dfn[i])Tarjan_bcc(i,-1);
    printf("%d %d\n",ans1,ans2);
  }
}
