/*************************************************************************
     File Name: E.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月02日 星期二 12时38分41秒
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
const int N=15;
struct node{
  int x,y;
  node(int _x,int _y):x(_x),y(_y){};
};
char mp[N][N];
bool vis_r[N][N],vis_c[N][N],vis[4][4][N],visit[N];
bool flag;
vector<node> v;

bool check() {
  int i,j,k,l;
  for (i=1; i<=9; ++i) {
    Mem0(visit);
    for (j=1; j<=9; ++j)
      visit[mp[i][j]-'0']=1;
    for (j=1; j<=9; ++j)
      if (!visit[j]) return 0;
  }
  for (i=1; i<=9; ++i) {
    Mem0(visit);
    for (j=1; j<=9; ++j)
      visit[mp[j][i]-'0']=1;
    for (j=1; j<=9; ++j)
      if (!visit[j]) return 0;
  }
  for (k=0; k<3; ++k)
    for (l=0; l<3; ++l) {
      Mem0(visit);
      for (i=1; i<=3; ++i)
        for (j=1; j<=3; ++j)
          visit[mp[k*3+i][l*3+j]-'0']=1;
      for (i=1; i<=9; ++i)
        if (!visit[i]) return 0;
    }
  return 1;
}

void dfs(int x) {
  if (flag) return;
  if (x==v.size()) {
    if (check()) flag=1;
    return;
  }
  for (int i=1; i<=9; ++i) {
    if (vis_r[v[x].x][i]) continue;
    if (vis_c[v[x].y][i]) continue;
    if (vis[(v[x].x+2)/3][(v[x].y+2)/3][i]) continue;
    mp[v[x].x][v[x].y]=i+'0';
    dfs(x+1);
    if (flag) return;
    mp[v[x].x][v[x].y]='0';
  }
}

void init() {
  flag=0;v.clear();
  Mem0(vis),Mem0(vis_r),Mem0(vis_c);
}

int main() {
  int t,i,j,k;
  while (~scanf("%d",&t)) {
    while (t--) {
      init();
      for (i=1; i<=9; ++i) {
        scanf("%s",mp[i]+1);
        for (j=1; j<=9; ++j) {
          if (mp[i][j]=='0')
            v.pb(node(i,j));
          int tmp=mp[i][j]-'0';
          vis_r[i][tmp]=1;
          vis_c[j][tmp]=1;
          vis[(i+2)/3][(j+2)/3][tmp]=1;
        }
      }
      dfs(0);
      if (flag) {
        for (i=1; i<=9; ++i)
          printf("%s\n",mp[i]+1);
      } else puts("Could not complete this grid.");
      if (t) puts("");
    }
  }
}
