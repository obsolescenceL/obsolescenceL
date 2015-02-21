/*************************************************************************
     File Name: HDU1233_Kruskal.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月27日  9:42:25
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=100;
int n,m,pre[MAXN];
struct Edge{
  int a,b,c;
  bool operator < (const Edge& rhs) const{
    return c<rhs.c;
  }
}edge[MAXN*MAXN/2];

inline void init(){
  for(int i=1;i<=n;i++)pre[i]=i;
}

inline int find(int x){
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

inline void Union(int x,int y){
  pre[find(y)]=find(x);
}

inline void Kruskal(){
  int i,sum=0;
  init();
  sort(edge,edge+m);
  for(i=0;i<m;i++){
    if(find(edge[i].a)!=find(edge[i].b)){
      Union(edge[i].a,edge[i].b);
      sum+=edge[i].c;
    }
  }
  printf("%d\n",sum);
}

int main(){
  while(~scanf("%d",&n)&&n){
    m=n*(n-1)/2;
    for(int i=0;i<m;i++)
      scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
    Kruskal();
  }
}
