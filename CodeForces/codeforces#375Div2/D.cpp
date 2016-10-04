/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一 10/ 3 19:26:20 2016
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
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N=110;
char mp[N][N];
int mx[]={0,0,1,-1},my[]={1,-1,0,0},n,m;
struct node{
  int num,x,y;
  bool operator < (const node &rhs) const {
    return num < rhs.num;
  }
}ans[N*N],s,t;

bool vis[N][N];

void dfs(int x,int y) {
  mp[x][y]='*';
  for (int i=0; i<4; ++i) {
    int dx=x+mx[i],dy=y+my[i];
    if (dx>=0 && dx<n && dy>=0 && dy<m && mp[dx][dy]!='*') dfs(dx,dy);
  }
}

int bfs(int x,int y) {
  int i,num=0;
  s.x=x,s.y=y;
  vis[x][y]=1;
  queue<node> q;
  q.push(s);
  bool flag=0;
  while (!q.empty()) {
    s=q.front();
    q.pop();
    num++;
    if (s.x==0 || s.y==0 || s.x==n-1 || s.y==m-1) flag=1;
    for (i=0; i<4; ++i) {
      t.x=s.x+mx[i];
      t.y=s.y+my[i];
      if (t.x<0 || t.y<0 || t.x>=n || t.y>=m)
        continue;
      if (mp[t.x][t.y]!='.') continue;
      if (vis[t.x][t.y]) continue;
      vis[t.x][t.y]=1;
      q.push(t);
    }
  }
  if (flag) return 0;
  return num;
}

int main() {
  int k,i,j,cnt=0;
  MEM0(vis);
  cin>>n>>m>>k;
  for (i=0; i<n; ++i) cin>>mp[i];
  for (i=0; i<n; ++i) {
    for (j=0; j<m; ++j) {
      if (mp[i][j]=='.' && !vis[i][j]) {
        int tmp=bfs(i,j);
        if (tmp) {
          ans[cnt].x=i;
          ans[cnt].y=j;
          ans[cnt++].num=tmp;
        }
      }
    }
  }
  sort(ans,ans+cnt);
  int sum=0;
  for (i=0; i<cnt-k; ++i) {
    sum+=ans[i].num;
    dfs(ans[i].x,ans[i].y);
  }
  cout<<sum<<endl;
  for (i=0; i<n; ++i) cout<<mp[i]<<endl;
}
