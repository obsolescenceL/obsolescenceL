/*************************************************************************
    > File Name: HDU1242.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 8日 14:52:11
 ************************************************************************/
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
char mapp[210][210];
int n,m,mapx[]={0,1,0,-1},mapy[]={1,0,-1,0};
int step[210][210],visit[210][210];
struct node{
  int x,y;
}a,b;
int main(){
  int i,j,x,y;
  while(~scanf("%d%d",&n,&m)){
    memset(step,0,sizeof(step));
    memset(visit,0,sizeof(visit));
    queue<node>q;
    int flag=1,min_step=1e9;
    for(i=0;i<n;i++)
      scanf("%s",mapp[i]);
    for(i=0;i<n;i++){
      for(j=0;j<m;j++)
        if(mapp[i][j]=='r')break;
      if(mapp[i][j]=='r')break;
    }
    a.x=i,a.y=j;
    q.push(a);
    //printf("%d %d\n",q.front().x,q.front().y);
    while(!q.empty()){
      a=q.front();
      q.pop();
      for(int k=0;k<4;k++){
        b.x=a.x+mapx[k],b.y=a.y+mapy[k];
        if(b.x>=0&&b.x<n&&b.y>=0&&b.y<m&&mapp[b.x][b.y]!='#'&&!visit[b.x][b.y]){
          visit[b.x][b.y]=1;
          q.push(b);
          //printf("%d %d\n",q.front().x,q.front().y);
          if(mapp[b.x][b.y]=='x')step[b.x][b.y]=step[a.x][a.y]+2;
          else if(mapp[b.x][b.y]=='a'){
            step[b.x][b.y]=step[a.x][a.y]+1,flag=0;
            if(step[b.x][b.y]<min_step)
              min_step=step[b.x][b.y];
          }
          else step[b.x][b.y]=step[a.x][a.y]+1;
          //printf("step[%d][%d]=%d\n",b.x,b.y,step[b.x][b.y]);
        }
      }
    }
    if(flag)
      puts("Poor ANGEL has to stay in the prison all his life.");
    else printf("%d\n",min_step);
  }
}
