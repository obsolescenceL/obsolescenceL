/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月11日 13:39:37
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=110;
int pre[MAXN],N;
bool vis[MAXN][MAXN];

int find(int x){
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

void Union(int x,int y){
  int fx=find(x),fy=find(y);
  if(fx!=fy){
    pre[fx]=fy;
    N--;
  }
}

int main(){
  int i,j,n,m,nn,x,y;
  while(~scanf("%d%d",&n,&m)){
    N=n;
    int cnt=0;
    for(i=1;i<=n;++i){
      pre[i]=i;
      scanf("%d",&nn);
      if(!nn)cnt++;
      for(j=1;j<=nn;++j){
        scanf("%d",&x);
        vis[i][x]=1;
      }
    }
    //cout<<"gege"<<endl;
    for(i=1;i<=m;++i){
      int first=1;
      for(j=1;j<=n;++j){
        if(vis[j][i]&&first)vis[j][i]=0,x=j,first=0;
        else if(vis[j][i])vis[j][i]=0,Union(x,j);
      }
    }
    printf("%d\n",max(cnt,N-1));
  }
}
