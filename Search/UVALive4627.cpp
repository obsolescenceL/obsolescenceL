/*************************************************************************
     File Name: 4_6a.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月07日 星期二 18时37分44秒
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
using namespace std;
int mp[1001][1001],sea[100001],ans[100001],now;
bool vis[1001][1001];
int n,m,y,mx[]={0,0,1,-1},my[]={1,-1,0,0};
int pre[1001*1001];

struct node{
  int x,y;
  node(int _x=0,int _y=0):x(_x),y(_y){}
  bool operator < (const node& rhs) const {
    return mp[x][y]<mp[rhs.x][rhs.y];
  }
}s,t;

priority_queue<node> q;

int Num(int r,int c){
  return r*m+c;
}

int find(int x){
  return x==pre[x]?x:pre[x]=find(pre[x]);
}

void Union(int x,int y){
  int fx=find(x),fy=find(y);
  if(fx!=fy){
    pre[fy]=fx;
    now--;
  }
}

void bfs(){
  int i,j;
  memset(vis,0,sizeof vis);
  now=0;
  for(i=1;i<=y;++i){
    while(!q.empty()&&mp[q.top().x][q.top().y]>sea[i]){
      s=q.top();q.pop();
      vis[s.x][s.y]=1;
      now++;
      for(j=0;j<4;++j){
        t.x=s.x+mx[j],t.y=s.y+my[j];
        if(0<=t.x&&t.x<n&&0<=t.y&&t.y<m&&vis[t.x][t.y])
          Union(Num(t.x,t.y),Num(s.x,s.y));
      }
    }
    ans[i]=now;
  }
  for(i=y;i;--i)printf("%d ",ans[i]);
  puts("");
}

int main(){
  int t,i,j;
  while(~scanf("%d",&t)){
    while(t--){
      while(!q.empty())q.pop();
      scanf("%d%d",&n,&m);
      for(i=0;i<n;++i)
        for(j=0;j<m;++j){
          scanf("%d",&mp[i][j]);
          pre[Num(i,j)]=Num(i,j);
          q.push(node(i,j));
        }
      scanf("%d",&y);
      for(i=y;i;--i)scanf("%d",sea+i);
      bfs();
    }
  }
}
