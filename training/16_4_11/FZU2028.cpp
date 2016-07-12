/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  4/11 17:47:23 2016
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
const int N=510,M=1e5+10;
struct transfer{
  int x,y;
}tran;
vector<transfer> v[N][N];
bool vis[N][N];
int mx[]={0,0,1,-1},my[]={1,-1,0,0},n,m;
char mp[N][N];

struct node{
  int x,y,step;
}s,t;

void bfs(){
  Mem0(vis);
  queue<node> q;
  q.push(s);
  vis[s.x][s.y]=1;
  each(it,v[s.x][s.y]){
    t.x=it->x;
    t.y=it->y;
    t.step=s.step+1;
    if(t.x<0 || t.x>=n || t.y<0 || t.y>=m)continue;
    if(vis[t.x][t.y] || mp[t.x][t.y]=='#')continue;
    vis[t.x][t.y]=1;
    q.push(t);
  }
  int i;
  while(!q.empty()){
    s=q.front();
    q.pop();
    if(mp[s.x][s.y]=='t'){
      printf("%d\n",s.step);
      return;
    }
    for(i=0;i<4;++i){
      t.x=s.x+mx[i];
      t.y=s.y+my[i];
      t.step=s.step+1;
      if(t.x<0 || t.x>=n || t.y<0 || t.y>=m)continue;
      if(vis[t.x][t.y] || mp[t.x][t.y]=='#')continue;
      vis[t.x][t.y]=1;
      q.push(t);
    }
    each(it,v[s.x][s.y]){
      t.x=it->x;
      t.y=it->y;
      t.step=s.step+1;
      if(t.x<0 || t.x>=n || t.y<0 || t.y>=m)continue;
      if(vis[t.x][t.y] || mp[t.x][t.y]=='#')continue;
      vis[t.x][t.y]=1;
      q.push(t);
    }
  }
}

int main(){
  int i,j,k,l;
  while(~scanf("%d%d",&n,&m)){
    for(i=0;i<n;++i){
      scanf("%s",mp[i]);
      for(j=0;j<m;++j){
        v[i][j].clear();
        //cout<<"v[i][j].size()="<<v[i][j].size()<<endl;
        if(mp[i][j]=='s')
          s.x=i,s.y=j,s.step=0;
      }
    }
    for(i=0;i<n;++i)
      for(j=0;j<m;++j){
        scanf("%d",&k);
        for(l=0;l<k;++l){
          scanf("%d%d",&tran.x,&tran.y);
          tran.x--;
          tran.y--;
          v[i][j].pb(tran);
        }
      }
    bfs();
  }
}
