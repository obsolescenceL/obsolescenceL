/*************************************************************************
     File Name: e.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月28日 星期六 13时26分32秒
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
using namespace std;
char mp[100][100];
bool vis[100][100];
int mx[]={1,-1,0,0},my[]={0,0,1,-1};
struct node{
  int x,y,step;
}a,t;
queue<node> q;
int n,i;

int main(){
  while(~scanf("%d%d%d",&n,&a.x,&a.y)){
    memset(vis,0,sizeof vis);
    while(!q.empty())q.pop();
    for(i=0;i<n;++i)
      scanf("%s",mp[i]);
    a.x--,a.y--,a.step=1;
    vis[a.x][a.y]=1;
    q.push(a);
    while(!q.empty()){
      a=q.front();q.pop();
      if(mp[a.x][a.y]=='#')break;
      for(i=0;i<4;++i){
        t.x=a.x+mx[i];
        t.y=a.y+my[i];
        t.step=a.step+1;
        if(t.x>=0&&t.y>=0&&t.x<n&&t.y<n&&!vis[t.x][t.y])
          q.push(t),vis[t.x][t.y]=1;

      }
    }
    printf("%d\n",a.step);
  }
}
