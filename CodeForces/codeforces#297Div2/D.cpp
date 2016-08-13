/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月27日 星期五 01时25分30秒
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
char mp[2002][2002];
bool vis[2002][2002];
int mx[]={1,-1,1,-1,0,0,0,0},my[]={1,-1,0,0,0,0,1,-1};
int n,m;

bool check_is_ok(int x,int y){
  int cnt=0;
  if(x==0||x==n-1||y==0||y==m-1)cnt++;
  for(int i=0;i<8;++i)
    if(mp[x+mx[i]][y+my[i]]=='.')cnt++;
  if(cnt>=5)return 1;
  else return 0;
}

void dfs(int x,int y){
  //puts("-------------");
  if(vis[x][y]||mp[x][y]=='.'||x>=n||x<0||y>=m||y<0)return;
  vis[x][y]=1;
  if(check_is_ok(x,y))mp[x][y]='.';
  for(int i=0;i<8;++i){
    int dx=x+mx[i],dy=y+my[i];
    //cout<<"dx="<<dx<<" dy="<<dy<<endl;
    dfs(dx,dy);
  }
  return;
}

int main(){
  int i;
  while(~scanf("%d%d",&n,&m)){
    for(i=0;i<n;++i){
      scanf("%s",mp[i]);
    }
    memset(vis,0,sizeof vis);
    dfs(0,0);
    //puts("-------------");
    memset(vis,0,sizeof vis);
    dfs(n-1,m-1);
    for(i=0;i<n;++i){
      printf("%s\n",mp[i]);
    }
    puts("-------------");
  }
}
