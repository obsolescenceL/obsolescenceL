/*************************************************************************
     File Name: HDU1879_Kruskal.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月27日 14:15:05
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=100;
int pre[MAXN],n,m;
struct Edge{
  int a,b,c;
  bool operator < (const Edge& rhs)const{
    return c<rhs.c;
  }
}edge[MAXN*MAXN/2];

inline void init(){
  for(int i=1;i<=n;++i)pre[i]=i;
}

inline int find(int x){
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

inline void Union(int x,int y){
  pre[find(x)]=find(y);
}

inline void Kruskal(){
  sort(edge,edge+m);
  int sum=0,i;
  for( i=0;i<m;i++)
    if(find(edge[i].a)!=find(edge[i].b)){
      Union(edge[i].a,edge[i].b);
      sum+=edge[i].c;
    }
  printf("%d\n",sum);
}

int main(){
  int i,flag;
  while(~scanf("%d",&n)&&n){
    init();
    m=n*(n-1)/2;
    for(i=0;i<m;i++){
      scanf("%d%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c,&flag);
      if(flag)Union(edge[i].a,edge[i].b);
    }
    Kruskal();
  }
}
