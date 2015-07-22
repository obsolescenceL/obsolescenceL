/*************************************************************************
     File Name: POJ1470.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月22日 星期三 13时52分13秒
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
const int N=1000;
int n,top,pre[N],cnt[N];bool vis[N],root[N];
vector<int> qes[N];
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N<<1];

void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from];
  head[from]=p;
}

int find(int x){
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

void Union(int x,int y){
  x=find(x),y=find(y);
  if(x!=y)pre[y]=x;
}

void Tarjan_lca(int u){
  for(Edge *p=head[u];p;p=p->next){
    Tarjan_lca(p->to);
    Union(u,p->to);
  }
  vis[u]=1;
  for(int i=0;i<qes[u].size();++i)
    if(vis[qes[u][i]])
      cnt[find(qes[u][i])]++;
}

void init(){
  Mem0(root),Mem0(vis),Mem0(head),Mem0(cnt);
  for(int i=0;i<=n;++i)pre[i]=i,qes[i].clear();
  top=0;
}

int main(){
  int i,j,s,d,m;
  while(~scanf("%d",&n)){
    init();
    //cout<<"n="<<n<<endl;
    for(i=0;i<n;++i){
      scanf("%d:(%d)",&s,&m);
      //cout<<"s="<<s<<" m="<<m<<endl;
      for(j=0;j<m;++j){
        scanf("%d",&d);
        //cout<<"d="<<d<<endl;
        Addedge(s,d);
        root[d]=1;
      }
    }
    scanf("%d",&m);
    //cout<<"m="<<m<<endl;
    for(j=0;j<m;++j){
      scanf(" (%d %d)",&s,&d);
      //cout<<'('<<s<<' '<<d<<')'<<endl;
      qes[s].pb(d),qes[d].pb(s);
    }
    for(i=1;i<=n;++i)
      if(!root[i]){
        Tarjan_lca(i);
        break;
      }
    for(i=1;i<=n;++i)
      if(cnt[i])printf("%d:%d\n",i,cnt[i]);
  }
}
