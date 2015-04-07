/*************************************************************************
     File Name: 4_6d.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月07日 星期二 15时28分16秒
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
const int INF=0x3f3f3f3f;
char mp[55][55];
int mx[]={0,0,1,-1},my[]={1,-1,0,0},n,m;
bool vis[55][55];

struct Transfer{
  int x1,y1,x2,y2;
  bool flag;
}trans[30];

struct node{
  int x,y,step;
}s;

void bfs(){
  queue<node> q;
  q.push(s);
  vis[s.x][s.y]=1;
  bool flag=1;
  int min_step=INF,i;
  while(!q.empty()){
    s=q.front();
    q.pop();
    node t;
    for(i=0;i<4;++i){
      t.x=s.x+mx[i],t.y=s.y+my[i],t.step=s.step+1;
      if(t.x>=0&&t.y>=0&&t.x<n&&t.y<m&&mp[t.x][t.y]!='#'&&!vis[t.x][t.y]){
        vis[t.x][t.y]=1;
        if(mp[t.x][t.y]=='Q'){
          flag=0;
          min_step=Min(min_step,t.step);
        }else if(mp[t.x][t.y]!='.'){
          int x=mp[t.x][t.y]-'a';
          if(trans[x].x1==t.x&&trans[x].y1==t.y){
            t.x=trans[x].x2;
            t.y=trans[x].y2;
          }else{
            t.x=trans[x].x1;
            t.y=trans[x].y1;
          }
        }
        q.push(t);
      }
    }
  }
  if(flag)puts("-1");
  else printf("%d\n",min_step);
}

int main(){
  int t,i,j;
  ios::sync_with_stdio(0);
  while(cin>>t){
    while(t--){
      memset(trans,0,sizeof trans);
      memset(vis,0,sizeof vis);
      cin>>n>>m;
      for(i=0;i<n;++i)cin>>mp[i];
      for(i=0;i<n;++i)
        for(j=0;j<m;++j){
          int x=mp[i][j]-'a';
          if(mp[i][j]=='L')s.x=i,s.y=j,s.step=0;
          else if(x>=0&&x<26){
            if(trans[x].flag)trans[x].x2=i,trans[x].y2=j;
            else trans[x].x1=i,trans[x].y1=j,trans[x].flag=1;
          }
        }
      bfs();
    }
  }
}
