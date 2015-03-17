/*************************************************************************
     File Name: POJ1251.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月29日  9:16:13
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=30;
int n,d[MAXN],adj[MAXN][MAXN];
bool vis[MAXN];

inline void Prim(){
  int i,j,sum=0;
  memset(d,0x3F,sizeof d);
  memset(vis,0,sizeof vis);
  d[1]=0;
  for(i=0;i<n;++i){
    int a=-1,minn=100;
    for(j=0;j<n;++j)
      if(!vis[j] && d[j]<minn)
        a=j,minn=d[j];
    if(a==-1)break;
    vis[a]=1;
    sum+=minn;
    //cout<<sum<<endl;
    for(j=0;j<n;++j)
      if(adj[a][j] && !vis[j] && adj[a][j]<d[j])
        d[j]=adj[a][j];
  }
  printf("%d\n",sum);
}

int main(){
  char x[2],y[2];
  int nn,m,w;
  while(~scanf("%d",&n)&&n){
    memset(adj,0,sizeof adj);
    nn=n;
    while((nn--)-1){
      scanf("%s%d",x,&m);
      //cout<<"x="<<x[0]<<' ';
      while(m--){
        scanf("%s%d",y,&w);
        //cout<<"y="<<y[0]<<' ';
        adj[x[0]-'A'][y[0]-'A']=w;
        adj[y[0]-'A'][x[0]-'A']=w;
      }
      //cout<<endl;
    }
    Prim();
  }
}
