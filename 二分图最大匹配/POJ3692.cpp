/*************************************************************************
    > File Name: POJ3692.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月11日  8:55:16
 ************************************************************************/
#include<cstdio>
#include<cstring>
const int MAXN=205;
typedef int array[MAXN];
array my,visit_y;
int nx,ny,a,b,m,k=1;
bool adj[MAXN][MAXN];

bool DFS(int x){
  for(int y=1;y<=ny;y++){
    if(!visit_y[y] && !adj[x][y]){
      visit_y[y]=1;
      if(!my[y] || DFS(my[y])){
        my[y]=x;
        return 1;
      }
    }
  }
  return 0;
}

void Hungary(){
  memset(my,0,sizeof my);
  int cnt=0;
  for(int x=1;x<=nx;x++){
    memset(visit_y,0,sizeof visit_y);
    if(DFS(x))cnt++;
  }
  printf("Case %d: %d\n",k++,nx+ny-cnt);
}

int main(){
  while(scanf("%d%d%d",&nx,&ny,&m),nx||ny||m){
    memset(adj,0,sizeof adj);
    while(m--){
      scanf("%d%d",&a,&b);
      adj[a][b]=1;
    }
    Hungary();
  }
}
