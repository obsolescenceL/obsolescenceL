/*************************************************************************
     File Name: HDU1401_dbfs.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月23日 19:23:49
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
char vis[8][8][8][8][8][8][8][8];
int mx[]={0,0,1,-1},my[]={1,-1,0,0};
struct point{
  int x,y;
};
struct node{
  point p[4];
  int step;
}s[2];

int cmp(point p,point q){
  if(p.x==q.x)return p.y<q.y;
  return p.x<q.x;
}

void set1(node t){
  vis[t.p[0].x][t.p[0].y][t.p[1].x][t.p[1].y][t.p[2].x][t.p[2].y][t.p[3].x][t.p[3].y]='1';
}

void set2(node t){
  vis[t.p[0].x][t.p[0].y][t.p[1].x][t.p[1].y][t.p[2].x][t.p[2].y][t.p[3].x][t.p[3].y]='2';
}

char isvisit(node t){
  return vis[t.p[0].x][t.p[0].y][t.p[1].x][t.p[1].y][t.p[2].x][t.p[2].y][t.p[3].x][t.p[3].y];
}

int judge(node &t,int i,int j,int flag){
  if(flag){
    if(t.step>=4) 
      return 0;
    t.step++;    
  }
  t.p[i].x+=mx[j];
  t.p[i].y+=my[j];
  if(t.p[i].x>=0&&t.p[i].x<8&&t.p[i].y>=0&&t.p[i].y<8){
    int k;
    for(k=0;k<4;k++){
      if(i!=k){
        if(t.p[i].x==t.p[k].x&& t.p[i].y==t.p[k].y)    
          if(flag) return judge(t,i,j,0); 
          else return 0;    
      }    
    }
    if(k>=4){
      sort(t.p,t.p+4,cmp);
      return 1;
    }
  }
  return 0;
}

bool dbfs(){
  queue<node> q[2];
  node t;
  int i,j,k;
  q[0].push(s[0]),q[1].push(s[1]);
  set1(s[0]),set2(s[1]);
  while(!q[0].empty()||!q[1].empty()){
    for(k=0;k<2;k++){
      if(q[k].empty())continue;
      for(i=0;i<4;i++)
        for(j=0;j<4;j++){
          t=q[k].front();
          if(judge(t,i,j,1)){
            if(isvisit(t)-'1'==k)continue;
            if(isvisit(t)-'1'==1-k)return 1;
            q[k].push(t);
            if(k)set2(t);
            else set1(t);
          }
        }
      q[k].pop();
    }
  }
  return 0;
}

int main(){
  int i,x,y;
  while(~scanf("%d%d",&x,&y)){
    memset(vis,0,sizeof vis);
    s[0].p[0].x=x-1,s[0].p[0].y=y-1;
    for(i=1;i<4;i++)scanf("%d%d",&x,&y),s[0].p[i].x=x-1,s[0].p[i].y=y-1;
    for(i=0;i<4;i++)scanf("%d%d",&x,&y),s[1].p[i].x=x-1,s[1].p[i].y=y-1;
    s[0].step=s[1].step=0;
    sort(s[0].p,s[0].p+4,cmp);
    sort(s[1].p,s[1].p+4,cmp);
    dbfs()? puts("YES"):puts("NO");
  }
}
