/*************************************************************************
     File Name: UESTC1088.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月02日 星期二 10时08分59秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<queue>
#define Mem0(x) memset(x,0,sizeof(x))
using namespace std;
const int N=35;
char mp[N][N][N];
int mz[]={0,0,1,-1,0,0};
int mx[]={1,-1,0,0,0,0};
int my[]={0,0,0,0,1,-1},l,r,c;
bool vis[N][N][N];
struct status{
  int z,x,y,step;
  status(int _z=0,int _x=0,int _y=0,int _step=0):z(_z),x(_x),y(_y),step(_step){}
}s,e;

void Bfs(){
  int ans=-1,i,z,x,y,step;
  status t;
  queue<status> q;
  Mem0(vis);
  vis[s.z][s.x][s.y]=1;
  q.push(s);
  while(!q.empty()){
    t=q.front();
    q.pop();
    if(t.z==e.z&&t.x==e.x&&t.y==e.y){
      ans=t.step;
      break;
    }
    for(i=0;i<6;++i){
      z=t.z+mz[i];
      x=t.x+mx[i];
      y=t.y+my[i];
      step=t.step+1;
      if(vis[z][x][y])continue;
      if(mp[z][x][y]=='#')continue;
      if(0>z||z>=l||0>x||x>=r||0>y||y>=c)continue;
      vis[z][x][y]=1;
      q.push(status(z,x,y,step));
    }
  }
  if(ans==-1)puts("Trapped!");
  else printf("Escaped in %d minute(s).\n",ans);
}

int main(){
  int i,j,k;
  while(~scanf("%d%d%d",&l,&r,&c)&&(l||r||c)){
    for(i=0;i<l;++i){
      for(j=0;j<r;++j){
        scanf("%s",mp[i][j]);
        for(k=0;k<c;++k){
          if(mp[i][j][k]=='S')
            s.z=i,s.x=j,s.y=k,s.step=0;
          if(mp[i][j][k]=='E')
            e.z=i,e.x=j,e.y=k;
        }
      }
      getchar();
    }
    Bfs();
  }
}
