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
#include<queue>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
using namespace std;
const int INF=0x3f3f3f3f;
char mp[51][51];
int mx[]={0,0,1,-1},my[]={1,-1,0,0},n,m;
bool vis[51][51];

struct Transfer{
  int x1,y1,x2,y2;
  bool flag;
}trans[26];

struct Status{
  int x,y,step;
}s,t;

void bfs(){
  memset(vis,0,sizeof vis);
  queue<Status> q;
  q.push(s);
  vis[s.x][s.y]=1;
  bool flag=1;
  int ans,i,x;
  while(!q.empty()&&flag){
    s=q.front();
    q.pop();
    for(i=0;i<4;++i){
      t.x=s.x+mx[i],t.y=s.y+my[i],t.step=s.step+1;
      if(0<=t.x&&t.x<n&&0<=t.y&&t.y<m&&mp[t.x][t.y]!='#'&&!vis[t.x][t.y]){
        vis[t.x][t.y]=1;
        if(mp[t.x][t.y]=='Q'&&flag){
          flag=0;
          ans=t.step;
          break;
        }else if(mp[t.x][t.y]!='.'){
          x=mp[t.x][t.y]-'a';
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
  else printf("%d\n",ans);
}

int main(){
  int t,i,j,x;
  while(~scanf("%d",&t)){
    while(t--){
      memset(trans,0,sizeof trans);
      scanf("%d%d",&n,&m);
      for(i=0;i<n;++i){
        scanf("%s",mp[i]);
        for(j=0;j<m;++j){
          x=mp[i][j]-'a';
          if(mp[i][j]=='L')s.x=i,s.y=j,s.step=0;
          else if(0<=x&&x<26){
            if(trans[x].flag)trans[x].x2=i,trans[x].y2=j;
            else trans[x].x1=i,trans[x].y1=j,trans[x].flag=1;
          }
        }
      }
      bfs();
    }
  }
}
