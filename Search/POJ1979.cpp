/*************************************************************************
    > File Name: POJ1979.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 7日 20:03:59
 ************************************************************************/
#include<cstdio>
#include<cstring>
char mapp[22][22];
int visit[22][22],mapx[]={1,0,0,-1},mapy[]={0,1,-1,0},w,h;
void DFS(int x,int y){
  for(int i=0;i<4;i++){
    int dx=x+mapx[i],dy=y+mapy[i];
    //printf("dx=%d,dy=%d ",dx,dy);
    if(!visit[dx][dy]&&dx>=0&&dy>=0&&dx<h&&dy<w&&mapp[dx][dy]=='.')
      visit[dx][dy]=1,DFS(dx,dy);
    //printf("visit[%d][%d]=%d ",dx,dy,visit[dx][dy]);
  }
}
int main(){
  while(scanf("%d%d",&w,&h),w||h){
    int i,j,num=1;
    memset(visit,0,sizeof(visit));
    for(i=0;i<h;i++)scanf("%s",mapp[i]);
    for(i=0;i<h;i++){
      for(j=0;j<w;j++)
        if(mapp[i][j]=='@')break;
      if(mapp[i][j]=='@')break;
    }
    //printf("%d %d,i j\n",i,j);
    DFS(i,j);
    for(i=0;i<h;i++)
      for(j=0;j<w;j++)
        if(visit[i][j])num++;
    printf("%d\n",num);
  }
}
