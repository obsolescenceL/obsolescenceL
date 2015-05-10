/*************************************************************************
     File Name: fangLaoShiDeFenShen2.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月14日 星期二 01时21分52秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>
#include<bitset>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
using namespace std;
const int N=5010,INF=0x3f3f3f3f;
int n,ans,top,dis[N][60];
bool flag[N][60];
struct Edge{
  int to,w;
  Edge *next;
}*head[N],e[N*40];
struct node{
  int now,cnt;
  node(int _now,int _cnt):now(_now),cnt(_cnt){}
};

void Addedge(int from,int to,int w){
  Edge *p=&e[++top];
  p->to=to,p->w=w,p->next=head[from],head[from]=p;
}

void SPFA(int s,int t,int k){
  memset(dis,0x3f,sizeof dis);
  memset(flag,0,sizeof flag);
  queue<node> q;
  ans=INF;
  dis[s][0]=0;
  flag[s][0]=1;
  q.push(node(s,0));
  while(!q.empty()){
    node x=q.front();
    q.pop();
    int now=x.now,cnt=x.cnt;
    if(now==t&&cnt>=k)ans=Min(ans,dis[now][cnt]);
    flag[now][cnt]=0;
    int temp,to,w;
    if(cnt+1>k)temp=k;// !!!
    else temp=cnt+1;
    for(Edge *p=head[now];p;p=p->next){
      to=p->to,w=p->w;
      if(dis[to][temp]>w+dis[now][cnt]){
        dis[to][temp]=w+dis[now][cnt];
        if(!flag[to][temp])
          flag[to][temp]=1,q.push(node(to,temp));
      }
    }
  }
}

int main(){
  int m,u,v,w,s,t,k;
  while(~scanf("%d%d",&n,&m)){
    top=0;
    memset(head,0,sizeof head);
    while(m--){
      scanf("%d%d%d",&u,&v,&w);
      Addedge(u,v,w);
      Addedge(v,u,w);
    }
    scanf("%d%d%d",&s,&t,&k);
    SPFA(s,t,k);
    if(ans==INF)puts("-1");
    else printf("%d\n",ans);
  }
}
