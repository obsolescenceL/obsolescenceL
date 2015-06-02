/*************************************************************************
     File Name: UESTC203.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月23日 星期六 23时32分07秒
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
const int N=1001;
int mp[N][N],sea[100*N],ans[100*N],pre[N*N];
int mx[]={0,0,-1,1},my[]={1,-1,0,0},now,n,m,year;
bool vis[N][N];

struct node{
  int x,y;
  node(int _x=0,int _y=0):x(_x),y(_y){}
  bool operator < (const node& rhs) const {
    return mp[x][y]<mp[rhs.x][rhs.y];
  }
}s,t;
priority_queue<node> q;

int Id(int r,int c){
  return r*m+c;
}

int find(int x){
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

void Union(int x,int y){
  int fx=find(x),fy=find(y);
  if(fx!=fy)pre[fy]=fx,now--;
}

void Bfs(){
  Mem0(vis),now=0;
  for(int i=1,j;i<=year;++i){
    while(!q.empty() && mp[q.top().x][q.top().y]>sea[i]){
      s=q.top(),q.pop();
      vis[s.x][s.y]=1;
      now++;
      for(j=0;j<4;++j){
        t.x=s.x+mx[j],t.y=s.y+my[j];
        if(0<=t.x && t.x<n && 0<=t.y && t.y<m && vis[t.x][t.y])
          Union(Id(t.x,t.y),Id(s.x,s.y));
      }
    }
    ans[i]=now;
  }
}


int main(){
  int i,j,t;
  while(~scanf("%d",&t)){
    while(t--){
      while(!q.empty())q.pop();
      scanf("%d%d",&n,&m);
      for(i=0;i<n;++i)
        for(j=0;j<m;++j){
          scanf("%d",mp[i]+j);
          pre[Id(i,j)]=Id(i,j);
          q.push(node(i,j));
        }
      scanf("%d",&year);
      for(i=year;i;--i)scanf("%d",sea+i);
      Bfs();
      for(i=year;i;--i)printf("%d ",ans[i]);
      puts("");
    }
  }
}
