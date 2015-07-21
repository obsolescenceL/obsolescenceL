/*************************************************************************
     File Name: HDU3844.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月21日 星期二 9时35分34秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#pragma comment(linker, "/STACK:102400000,102400000")
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define pb push_back
using namespace std;
const int N=100010;
int low[N],dfn[N],cnt[N],bcc_n,tim,top,n;
bool iscut[N];
stack<int> s;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N];
vector<int> v[N];

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
        bcc_n++;
        do{
          x=s.top(),s.pop();
          v[bcc_n].pb(x),cnt[x]++;
        }while(to!=x);
        v[bcc_n].pb(from),cnt[from]++;
      }
    }else low[from]=Min(low[from],dfn[to]);
  }
}

void init(){
  Mem0(head),Mem0(low),Mem0(dfn),Mem0(iscut),Mem0(cnt);
  while(!s.empty())s.pop();
  top=tim=bcc_n=n=0;
}

int main(){
  int m,p1,p2,i,j,x,nc(0);
  while(~scanf("%d",&m)&&m){
    init();
    while(m--){
      scanf("%d%d",&p1,&p2);
      Addedge(p1,p2),Addedge(p2,p1);
      n=Max(n,Max(p1,p2));
    }
    for(i=1;i<=n;++i)v[i].clear();
    for(i=1;i<=n;++i)if(!dfn[i])Tarjan_bcc(i,-1);
    for(i=1;i<=n;++i)if(cnt[i]>1)iscut[i]=1;
    ll ans1(0),ans2(1);
    for(i=1;i<=bcc_n;++i){
      int cut_n=0;
      if(v[i].size()==1 && iscut[v[i][0]])continue;
      for(j=0;j<v[i].size();++j)if(iscut[v[i][j]])cut_n++;
      if(cut_n==1)ans1++,ans2*=(ll)(v[i].size()-cut_n);
    }
    if(bcc_n==1)ans1=2,ans2=(ll)(v[1].size()*(v[1].size()-1)/2);
    printf("Case %d: %I64d %I64d\n",++nc,ans1,ans2);
  }
}
