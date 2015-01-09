/*************************************************************************
    > File Name: a.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 9日 16:19:48
 ************************************************************************/
#include<cstdio>
#include<cstring>
const int MAXN=510;
typedef int array[MAXN];
array my,vy; 
int k,nx,ny,a,b;
bool adj[MAXN][MAXN];
bool DFS(int x){
  for(int y=1;y<=ny;y++){
    if(adj[x][y] && !vy[y]){
      vy[y]=1;
      //printf("vy[%d]=%d ",y,vy[y]);
      if(!my[y] || DFS(my[y])){
        my[y]=x;
        return true;
      }
    }
  }
  return false;
}
int main(){
  while(scanf("%d",&k),k){
    memset(adj,0,sizeof adj);
    scanf("%d%d",&nx,&ny);
    for(int i=1;i<=k;i++){
      scanf("%d%d",&a,&b);
      adj[a][b]=1;
    }
    memset(my,0,sizeof my);
    int cnt=0;
    for(int x=1;x<=nx;x++){
      memset(vy,0,sizeof vy);
      if(DFS(x))cnt++;
    }
    printf("%d\n",cnt);
  }
}
