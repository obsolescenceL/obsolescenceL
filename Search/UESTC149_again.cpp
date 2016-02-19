/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年02月19日 星期五 19时45分57秒
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
const int N=60;
struct node{
  int x,y,step;
}s,t;
struct transfer{
  int x1,y1,x2,y2;
  bool flag;
}tsf[30];
char mp[N][N];
bool vis[N][N];
int n,m,mx[]={0,0,1,-1},my[]={1,-1,0,0};

void Bfs(){
  queue<node> q;
  q.push(s);
  vis[s.x][s.y]=1;
  bool flag=0;
  int ans,i;
  while(!q.empty()){
    s=q.front();
    q.pop();
    if(mp[s.x][s.y]=='Q'){
      ans=s.step,flag=1;
      break;
    }
    for(i=0;i<4;++i){
      t.x=s.x+mx[i];
      t.y=s.y+my[i];
      t.step=s.step+1;
      if(0>t.x || t.x>=n || 0>t.y || t.y>=m || vis[t.x][t.y] || mp[t.x][t.y]=='#')continue;
      vis[t.x][t.y]=1;
      if(mp[t.x][t.y]>='a' && mp[t.x][t.y]<='z'){
        int x=mp[t.x][t.y]-'a';
        if(tsf[x].x1==t.x && tsf[x].y1==t.y)t.x=tsf[x].x2,t.y=tsf[x].y2;
        else t.x=tsf[x].x1,t.y=tsf[x].y1;
        //cout<<"t("<<t.x<<","<<t.y<<")\n";
      }
      //cout<<"t("<<t.x<<","<<t.y<<")\n";
      q.push(t);
    }
  }
  if(flag)printf("%d\n",ans);
  else puts("-1");
}

int main(){
  int t,i,j;
  while(~scanf("%d",&t)){
    while(t--){
      Mem0(tsf),Mem0(vis);
      scanf("%d%d",&n,&m);
      for(i=0;i<n;++i){
        scanf("%s",mp[i]);
        for(j=0;j<m;++j)
          if(mp[i][j]=='L')
            s.x=i,s.y=j,s.step=0;
          else if(mp[i][j]>='a' && mp[i][j]<='z'){
            int x=mp[i][j]-'a';
            if(tsf[x].flag) tsf[x].x2=i,tsf[x].y2=j;
            else tsf[x].x1=i,tsf[x].y1=j,tsf[x].flag=1;
          }
      }
      Bfs();
    }
  }
}
