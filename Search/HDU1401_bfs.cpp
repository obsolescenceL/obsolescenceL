/*************************************************************************
     File Name: HDU1401.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月23日  8:55:13
 ************************************************************************/
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
bool mp[8][8];
bool visit[8][8][8][8][8][8][8][8];
int mx[]={0,0,1,-1};
int my[]={1,-1,0,0};
struct node{
  int x[4],y[4],steps;
}p;

void set(node t){
  visit[t.x[0]][t.y[0]][t.x[1]][t.y[1]][t.x[2]][t.y[2]][t.x[3]][t.y[3]]=1;
}

bool isvisit(node t){
  return visit[t.x[0]][t.y[0]][t.x[1]][t.y[1]][t.x[2]][t.y[2]][t.x[3]][t.y[3]];
}

bool isIn(int x,int y){
  if(x>=0&&x<8&&y>=0&&y<8)return 1;
  return 0;
}

bool isempty(node t,int k){
  for(int i=0;i<4;i++)
    if(i!=k&&t.x[i]==t.x[k]&&t.y[i]==t.y[k])
      return 0;
  return 1;
}

bool isok(node t){
  int i;
  for(i=0;mp[t.x[i]][t.y[i]] && i<4;i++);
  return (i==4);
}

bool bfs(){
  p.steps=0;
  if(isok(p))return 1;
  //cout<<isok(p)<<endl;
  queue<node> q;
  q.push(p);
  int i,k;
  node t;
  while(!q.empty()){
    p=q.front();
    q.pop();
    if(p.steps>=8)return 0;
    //cout<<p.steps<<endl;
    //cout<<q.size()<<endl;
    for(k=0;k<4;k++)
      for(i=0;i<4;i++){
        t=p;
        t.steps++,t.x[k]+=mx[i],t.y[k]+=my[i];
        if(!isIn(t.x[k],t.y[k]) || isvisit(t))continue;
        if(isempty(t,k)){
          //cout<<isok(t)<<endl;
          if(isok(t))return 1;
          set(t),q.push(t);
        }else{
          t.x[k]+=mx[i],t.y[k]+=my[i];
          if(isIn(t.x[k],t.y[k])&&!isvisit(t)&&isempty(t,k)){
            //cout<<isok(t)<<endl;
            if(isok(t))return 1;
            set(t),q.push(t);
          }
        }
      }
  }
  return 0;
}

int main(){
  int i,j,x,y;
  while(cin>>x>>y){
    memset(mp,0,sizeof mp);
    memset(visit,0,sizeof visit);
    p.x[0]=x-1,p.y[0]=y-1;
    //cout<<x<<' '<<y<<endl;
    for(i=1;i<4;i++){
      cin>>x>>y;
      //cout<<x<<' '<<y<<endl;
      p.x[i]=x-1,p.y[i]=y-1;
    }
    for(i=0;i<4;i++){
      cin>>x>>y;
      //cout<<x<<' '<<y<<endl;
      mp[x-1][y-1]=1;
    }
//    for(i=0;i<8;i++){
//      for(j=0;j<8;j++)cout<<mp[i][j]<<' ';
//      cout<<endl;
//    }
    if(bfs())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}
