/*************************************************************************
     File Name: UESTC709.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月09日 星期六 16时46分26秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#define Mem0(x) memset(x,0,sizeof(x))
using namespace std;
const int N=20000000;
char mp[20][20];
int mx[]={1,-1,0,0},my[]={0,0,1,-1};
int s_x,s_y,e_x,e_y,n,m,ans,len;
bool vis[N];
struct node{
  int x[20],y[20],step;
}s;
queue<node> q;

int get_nextdir(int cur,int pre,node s){
  int i,dx,dy;
  for(i=0;i<4;++i){
    dx=s.x[pre]+mx[i],dy=s.y[pre]+my[i];
    if(dx==s.x[cur] && dy==s.y[cur])return i;
  }
}

int Hash(int x,int y,node s){
  int hs=x*m+y;
  for(int i=1;i<len;++i)
    hs=hs*4+get_nextdir(i,i-1,s);
  return hs%N;
}

void Bfs(){
  while(!q.empty()){
    node t=q.front();q.pop();
    int x=t.x[0],y=t.y[0],i,dx,dy,len1;
    if(x==e_x && y==e_y){
      ans=t.step;
      return;
    }
    for(i=0;i<4;++i){
      dx=x+mx[i],dy=y+my[i];
      if(n<=dx || dx<0 || m<=dy || dy<0 || mp[dx][dy]=='#')continue;
      bool flag=0;
      if(len>=3)len1=len-1;
      for(int j=1;j<len1;++j)
        if(dx==t.x[j] && dy==t.y[j]){
          flag=1;
          break;
        }
      if(flag)continue;
      node s;
      s.x[0]=dx,s.y[0]=dy;
      for(int j=1;j<len;++j)
        s.x[j]=t.x[j-1],s.y[j]=t.y[j-1];
      int T=Hash(dx,dy,s);
      if(!vis[T])
        vis[T]=1,s.step=t.step+1,q.push(s);
    }
  }
}

int main(){
  int i,j,nc=0;
  while(~scanf("%d%d",&n,&m)){
    while(!q.empty())q.pop();
    len=0,ans=-1;
    Mem0(vis);
    for(i=0;i<n;++i){
      scanf("%s",mp[i]);
      for(j=0;j<m;++j){
        if(mp[i][j]=='@')e_x=i,e_y=j;
        if(isdigit(mp[i][j])){
          if(mp[i][j]=='1')s_x=i,s_y=j;
          s.x[mp[i][j]-'1']=i;
          s.y[mp[i][j]-'1']=j;
          mp[i][j]='.';
          len++;
        }
      }
    }
    s.step=0;
    int T=Hash(s_x,s_y,s);
    vis[T]=1;
    q.push(s);
    Bfs();
    printf("Case #%d: %d\n",++nc,ans);
  }
}
