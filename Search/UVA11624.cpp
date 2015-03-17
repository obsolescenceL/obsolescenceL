/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月12日 星期四 10时16分51秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int mp[1010][1010];
int mx[]={0,0,1,-1},my[]={1,-1,0,0};
char s[1010];
struct node{
  int x,y,step;
}start,end;

int main(){
  int t,n,m,i,j,sx,sy;
  while(~scanf("%d",&t)){
    while(t--){
      memset(mp,-1,sizeof mp);
      queue<node> q;
      scanf("%d%d",&n,&m);
      for(i=0;i<n;++i){
        scanf("%s",s);
        for(j=0;j<m;++j){
          if(s[j]=='J')sx=i,sy=j;
          if(s[j]=='.')mp[i][j]=-2;
          if(s[j]=='F'){
            mp[i][j]=0;
            start.x=i;
            start.y=j;
            start.step=0;
            q.push(start);
          }
        }
      }
      /*for(i=0;i<n;++i){
        for(j=0;j<m;++j){
          printf("%d ",mp[i][j]);
        }
        puts("");
      }*/
      while(!q.empty()){
        start=q.front();
        q.pop();
        for(i=0;i<4;++i){
          end.x=start.x+mx[i];
          end.y=start.y+my[i];
          end.step=start.step+1;
          if(end.x>=0&&end.x<n&&end.y>=0&&end.y<m&&mp[end.x][end.y]==-2){
            q.push(end);
            mp[end.x][end.y]=end.step;
          }
        }
      }
      /*puts("");
      for(i=0;i<n;++i){
        for(j=0;j<m;++j){
          printf("%d ",mp[i][j]);
        }
        puts("");
      }*/
      int ans=-1;
      start.x=sx,start.y=sy,start.step=1;
      q.push(start);
      mp[start.x][start.y]=-1;
      while(!q.empty()){
        start=q.front();
        q.pop();
        //printf("start=%d %d %d\n",start.x,start.y,start.step);
        if(start.x==n-1||start.x==0||start.y==m-1||start.y==0){
          ans=start.step;
          break;
        }
        //puts("gege");
        for(i=0;i<4;++i){
          end.x=start.x+mx[i];
          end.y=start.y+my[i];
          end.step=start.step+1;
          if(end.x>=0&&end.x<n&&end.y>=0&&end.y<m&&(mp[end.x][end.y]==-2||mp[end.x][end.y]>=end.step)){
            q.push(end);
            mp[end.x][end.y]=-1;
          }
        }
      }
      if(ans==-1)puts("IMPOSSIBLE");
      else printf("%d\n",ans);
    }
  }
}
