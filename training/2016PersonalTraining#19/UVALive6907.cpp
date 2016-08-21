/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日  8/21 15:35:00 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
const int N=110;
vector<int> g[N];
int ans;
bool vis[N];

void dfs(int ch,int pre,int &cnt_node,int &cnt_edge) {
  ++cnt_node;
  cnt_edge+=g[ch].size();
  vis[ch]=1;
  EACH(it,g[ch]) {
    if (*it==pre) continue;
    if (vis[*it]) continue;
    dfs(*it,pre,cnt_node,cnt_edge);
  }
}

bool check(int p1,int p2) {
  MEM0(vis);
  int cnt_node_p1=0,cnt_edge_p1=0;
  dfs(p1,p2,cnt_node_p1,cnt_edge_p1);
  MEM0(vis);
  int cnt_node_p2=0,cnt_edge_p2=0;
  dfs(p2,p1,cnt_node_p2,cnt_edge_p2);
  if (cnt_node_p1 != cnt_node_p2) return 0;
  if (cnt_edge_p1 != cnt_edge_p2) return 0;
  if (cnt_edge_p1 != cnt_node_p1*(cnt_node_p1-1)+1) return 0;//!!!
  return 1;
}

void init() {
  ans=0;
  for (int i=0; i<N; ++i) g[i].clear();
}

int main() {
  int t,n,m,p1,p2,i;
  while (~scanf("%d",&t)) {
    for (int nc=1; nc<=t; ++nc) {
      scanf("%d%d",&n,&m);
      init();
      while (m--) {
        scanf("%d%d",&p1,&p2);
        g[p1].pb(p2);
        g[p2].pb(p1);
      }
      for (i=1; i<=n; ++i)
        EACH(it,g[i])
          ans+=check(i,*it);
      printf("Case #%d: %d\n",nc,ans/2);
    }
  }
}
