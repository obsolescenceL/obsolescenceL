/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月12日 13:32:44
 ************************************************************************/
#include<cstdio>
#include<iostream>
using namespace std;
char mp[505][505];
int vis[505][505];
int mx[]={1,-1,0,0},my[]={0,0,1,-1};
int n,m,k;

void dfs(int x,int y){
  if(vis[x][y]||mp[x][y]!='.'||x<0||y<0||x>=n||y>=m)return;
  vis[x][y]=1;
  for(int i=0;i<4;++i){
    int dx=x+mx[i],dy=y+my[i];
    dfs(dx,dy);
  }
  if(k)k--,mp[x][y]='X';
}

int main(){
  int i,j;
  scanf("%d%d%d",&n,&m,&k);
  for(i=0;i<n;++i){
    scanf("%s",mp[i]);
  }
  for(i=0;i<n&&k;++i)
    for(j=0;j<m&&k;++j)
      dfs(i,j);
  for(i=0;i<n;++i) cout<<mp[i]<<endl;
}
