/*************************************************************************
     File Name: POJ1330.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月21日 星期二 14时49分19秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#define Mem0(x) memset(x,0,sizeof(x))
#define pb push_back
using namespace std;
const int N=10010;
int n,pre[N];
bool vis[N],root[N];
vector<int> v[N],qes[N];

int find(int x){
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

void Union(int x,int y){
  x=find(x),y=find(y);
  if(x!=y)pre[y]=x;
}

void Tarjan_lca(int u){
  for(int i=0;i<v[u].size();++i){
    Tarjan_lca(v[u][i]);
    Union(u,v[u][i]);
  }
  vis[u]=1;
  for(int i=0;i<qes[u].size();++i)
    if(vis[qes[u][i]]){
      printf("%d\n",find(qes[u][i]));
      return;
    }
}

void init(){
  Mem0(root),Mem0(vis);
  for(int i=0;i<=n;++i)
    v[i].clear(),qes[i].clear(),pre[i]=i;
}

int main(){
  int t,i,s,d;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&n);
      init();
      for(i=1;i<n;++i){
        scanf("%d%d",&s,&d);
        v[s].pb(d);
        root[d]=1;
      }
      scanf("%d%d",&s,&d);
      qes[s].pb(d),qes[d].pb(s);
      for(i=1;i<=n;++i)
        if(!root[i]){
          Tarjan_lca(i);
          break;
        }
    }
  }
}
