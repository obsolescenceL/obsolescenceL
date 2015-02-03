/*************************************************************************
    > File Name: POJ1562.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 7日 17:37:26
 ************************************************************************/
#include<cstdio>
int mapx[]={-1,-1,-1,0,0,1,1,1},mapy[]={-1,0,1,1,-1,-1,0,1},n,m;
char oil_map[110][110];
void DFS(int x,int y){
  for(int i=0;i<8;i++){
    int dx=x+mapx[i],dy=y+mapy[i];
    if(dx<n&&dx>=0&&dy<m&&dy>=0&&oil_map[dx][dy]=='@')
      oil_map[dx][dy]='*',DFS(dx,dy);
  }
}
int main(){
  while(scanf("%d%d",&n,&m),n||m){
    int i,j;
    for(i=0;i<n;i++) scanf("%s",oil_map[i]);
    int cnt=0;
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
        if(oil_map[i][j]=='@') cnt++, DFS(i,j);
    printf("%d\n",cnt);
  }
}
