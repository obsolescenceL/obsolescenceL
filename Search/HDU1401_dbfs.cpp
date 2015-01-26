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
char vis[16777777];
int num[]={1,8,64,512,4096,32768,262144,2097152};
int mx[]={0,0,1,-1},my[]={1,-1,0,0};
struct point{
  int x,y;
};
struct node{
  point p[4];
  int step;
}s[2];

int cmp(point p,point q){
  return (p.x==q.x&&p.y<q.y)||p.x<q.x;
}

int Hash(node a){
  sort(a.p,a.p+4,cmp);
  int sum=0,i;
  for(i=0;i<4;i++){
    sum+=a.p[i].x*num[i*2];
    sum+=a.p[i].y*num[i*2+1];
  }
  return sum;
}

char isvisit(node t){
  return vis[Hash(t)];
}

int judge(node &t,int i,int j,int flag){
  if(flag){
    if(t.step>=4) return 0;
    t.step++;    
  }
  t.p[i].x+=mx[j], t.p[i].y+=my[j];
  if(t.p[i].x>=0&&t.p[i].x<8&&t.p[i].y>=0&&t.p[i].y<8){
    int k;
    for(k=0;k<4;k++)
      if(i!=k&&t.p[i].x==t.p[k].x&& t.p[i].y==t.p[k].y)    
          if(flag) return judge(t,i,j,0); 
          else return 0;    
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
  int Hashs[2];
  for(i=0;i<2;i++)Hashs[i]=Hash(s[i]),vis[Hashs[i]]='1'+i;
  if(Hashs[0]==Hashs[1])return 1;
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
            vis[Hash(t)]='1'+k;
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
    puts(dbfs()? "YES":"NO");
  }
}
