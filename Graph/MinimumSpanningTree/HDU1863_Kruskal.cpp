/*************************************************************************
     File Name: HDU1863.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月26日 18:58:33
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=100;
int pre[MAXN];
int n,m,nn;
struct Edge{
  int a,b,c;
  bool operator < (const Edge& rhs)const {
    return c<rhs.c;
  }
}edge[MAXN];


inline void init(){
  for(int i=1;i<=m;i++)pre[i]=i;
}

inline int find(int x){
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

inline void Union(int x,int y){
  pre[find(y)]=find(x);
  //cout<<find(y)<<endl;
}

inline void Kruskal(){
  init();
  sort(edge,edge+n);
  int i,j,sum=0;
  for(j=0;j<n;j++){
    if(find(edge[j].a)!=find(edge[j].b)){
      Union(edge[j].a,edge[j].b);
      sum+=edge[j].c;
      nn--;
    }
  }
  if(nn==1)printf("%d\n",sum);
  else puts("?");
}

int main(){
  while(~scanf("%d%d",&n,&m)&&n){
    nn=m;
    for(int i=0;i<n;i++)
      scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
    Kruskal();
  }
}
