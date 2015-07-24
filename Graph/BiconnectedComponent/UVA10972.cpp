/*************************************************************************
     File Name: UVA10972.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月24日 星期五 15时19分10秒
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
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N*N*2];
int low[N],dfn[N],belong[N],tim,bcc_n,top,ans,degree[N];
stack<int> s;

void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

void Tarjan_bcc(int from,int pre){
  dfn[from]=low[from]=++tim;
  s.push(from);
  int to,x,flag=1;
  for(Edge *p=head[from];p;p=p->next){
    to=p->to;
    if(to==pre && flag){flag=0;continue;}
    if(!dfn[to]){
      Tarjan_bcc(to,from);
      low[from]=Min(low[from],low[to]);
      if(dfn[from]<low[to]){
        bcc_n++;
        do{
          x=s.top(),s.pop();
          belong[x]=bcc_n;
        }while(to!=x);
      }
    }else low[from]=Min(low[from],dfn[to]);
  }
}

void init(){
  Mem0(head),Mem0(dfn),Mem0(low),Mem0(degree);
  while(!s.empty())s.pop();
  bcc_n=top=tim=ans=0;
}

int main(){
  int n,m,p1,p2,i;
  while(~scanf("%d%d",&n,&m)){
    //cout<<"n="<<n<<" m="<<m<<endl;
    init();
    while(m--){
      scanf("%d%d",&p1,&p2);
      Addedge(p1,p2);
      Addedge(p2,p1);
    }
    for(i=1;i<=n;++i)
      if(!dfn[i]){
        Tarjan_bcc(i,-1);
        bcc_n++;
        while(!s.empty()){
          int x=s.top();
          s.pop();
          belong[x]=bcc_n;
        }
      }
    if(bcc_n==1){
      puts("0");
      continue;
    }
    for(i=1;i<=n;++i)
      for(Edge *p=head[i];p;p=p->next)
        if(belong[i]!=belong[p->to])
          degree[belong[i]]++;
    for(i=1;i<=bcc_n;++i)
      if(degree[i]==1)ans++;
      else if(!degree[i])ans+=2;
    printf("%d\n",(ans+1)>>1);
  }
}
