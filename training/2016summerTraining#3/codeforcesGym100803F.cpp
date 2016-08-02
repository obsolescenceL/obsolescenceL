/*************************************************************************
     File Name: F.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月02日 星期二 23时16分23秒
 ************************************************************************/
#include<bits/stdc++.h>
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
const int N=510;
int n,m,pre[N];
struct Edge{
  int a,b,c;
  bool operator < (const Edge &rhs) const {
    return c<rhs.c;
  }
}e[N*N/2];
bool vis[N*N/2];

int find(int x) {
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

void Union(int x,int y) {
  pre[y]=x;
}

void init() {
  for (int i=0; i<=n; ++i) pre[i]=i;
}

int Kruskal(int cur) {
  int i,sum=0,x,y,cnt=1;
  init();
  for (i=0; i<m; ++i) {
    if (i==cur) continue;
    x=find(e[i].a),y=find(e[i].b);
    if (x!=y) {
      vis[i]=1;
      Union(x,y);
      sum+=e[i].c;
    }
  }
  return sum;
}

int main() {
  int i;
  while (~scanf("%d%d",&n,&m)) {
    Mem0(vis);
    for (i=0; i<m; ++i)
      scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
    sort(e,e+m);
    int tmp=Kruskal(-1),ans=0,ans_cnt=0;
    for (i=0; i<m; ++i) {
      if (!vis[i]) continue;
      if (tmp==Kruskal(i)) continue;
      ans+=e[i].c;
      ans_cnt++;
    }
    printf("%d %d\n",ans_cnt,ans);
  }
}
