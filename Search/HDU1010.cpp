/*************************************************************************
     File Name: HDU1010.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月18日 16:55:05
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=10;
int n,m,t,dis,flag,visit[MAXN][MAXN];
int mx[]={0,0,1,-1};
int my[]={1,-1,0,0};
char mp[MAXN][MAXN];
int x0,x1,y0,y1,xn;

int Distance(int x,int y){
  return max(x-x1,x1-x)+max(y-y1,y1-y);
}

void DFS(int x,int y,int steps){
  if(flag)return;
  if(mp[x][y]=='D'&&steps==t)flag=1;
  if(steps>=t)return;
  dis=t-steps-Distance(x,y);
  if(dis<0||dis%2)return;
  for(int i=0;i<4;i++){
    int dx=x+mx[i],dy=y+my[i],dsteps=steps+1;
    //printf("dx=%d,dy=%d,dsteps=%d,visit=%d i=%d\n",dx,dy,dsteps,visit[dx][dy],i);
    if(!visit[dx][dy]&&mp[dx][dy]!='X'){
      visit[dx][dy]=1;
      DFS(dx,dy,dsteps);
      visit[dx][dy]=0;
    }
  }
}

int main(){
  int i,j;
  while(~scanf("%d%d%d",&n,&m,&t)&&(n||m||t)){
    //printf("t=%d\n",t);
    flag=xn=0;
    memset(visit,0,sizeof visit);
    for(i=0;i<MAXN;i++)
      for(j=0;j<MAXN;j++)
        mp[i][j]='X';
    for(i=1;i<=n;i++){
      for(j=1;j<=m;j++){
        cin>>mp[i][j];
        //printf("%c",mp[i][j]);
        if(mp[i][j]=='S'){
          x0=i,y0=j;
          visit[x0][y0]=1;
        }
        else if(mp[i][j]=='D')x1=i,y1=j;
        else if(mp[i][j]=='X')xn++;
      }
      //puts("");
    }
    if(n*m-xn>t) DFS(x0,y0,0);
    if(flag)puts("YES");
    else puts("NO");
  }
}
