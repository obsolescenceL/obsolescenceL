/*************************************************************************
    > File Name: HDU1253.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 8日 17:06:05
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=55;
int mapp[maxn][maxn][maxn];
int visit[maxn][maxn][maxn],step[maxn][maxn][maxn],x,y,z,mx[]={1,0,0,0,0,-1},my[]={0,1,0,0,-1,0},mz[]={0,0,1,-1,0,0};
struct node{
  int x,y,z;
}a,b;
int main(){
  int i,j,k,t,ti;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d%d%d",&z,&x,&y,&ti);
      memset(step,0,sizeof(step));
      memset(visit,0,sizeof(visit));
      queue<node>q;
      int min_step=1e9;
      for(i=0;i<z;i++)
      {
        for(j=0;j<x;j++)
        {
          for(k=0;k<y;k++)
          {
            scanf("%d",&mapp[i][j][k]);
            //printf("%d ",mapp[i][j][k]);
          }
          //puts("");
        }
        //puts("");
      }
      a.x=0,a.y=0,a.z=0;
      q.push(a);
      while(!q.empty()){
        a=q.front();
        q.pop();
        for(i=0;i<6;i++){
          b.x=a.x+mx[i],b.y=a.y+my[i],b.z=a.z+mz[i];
          if(b.x>=0&&b.x<x&&b.y>=0&&b.y<y&&b.z>=0&&b.z<z&&!mapp[b.z][b.x][b.y]&&!visit[b.z][b.x][b.y]){
            visit[b.z][b.x][b.y]=1;
            q.push(b);
            step[b.z][b.x][b.y]=step[a.z][a.x][a.y]+1;
            if(b.z==z-1&&b.x==x-1&&b.y==y-1){
              min_step=min(min_step,step[b.z][b.x][b.y]);
              break;
            }
          }
        }
        if(b.z==z-1&&b.x==x-1&&b.y==y-1)break;
      }
      if(min_step<=ti)printf("%d\n",min_step);
      else puts("-1");
    }
  }
}
