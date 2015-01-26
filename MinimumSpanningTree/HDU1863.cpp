/*************************************************************************
     File Name: HDU1863.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月26日 18:58:33
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=110;
int pre[MAXN];
int n,m;
struct Edge{
  int a,b,c;
}edge[MAXN];

bool operator < (const Edge& lhs,const Edge& rhs){
  return lhs.c<rhs.c;
}

int init(){
  for(int i=0;i<m;i++)pre[i]=i;
}

int find(int x){
  x==pre[x]? x:pre[x]=find(pre[x]);
}

void Union(int x,int y){
  pre[find(x)]=find(y);
}

void Kruskal(){
  init();
  sort(edge,edge+n);
  int i,j,sum=0;
  for(i=0,j=0;i<m-1&&j<n;i++){
    while(find(edge[j].a)==find(edge[j].b))j++;
    Union(edge[j].a,edge[j].b);
    sum+=edge[j].c;
    j++;
  }
  if(i==m-1)printf("%d\n",sum);
  else puts("?");
}

int main(){
  while(~scanf("%d%d",&n,&m)&&n){
    for(int i=0;i<n;i++)
      scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
    Kruskal();
  }
}
