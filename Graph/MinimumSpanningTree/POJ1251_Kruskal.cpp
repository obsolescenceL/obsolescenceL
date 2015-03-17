/*************************************************************************
     File Name: POJ1251_Kruskal.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月29日  9:52:54
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=30;
int pre[MAXN];
int n;
struct Edge{
  int x,y,w;
  bool operator < (const Edge& rhs)const{
    return w<rhs.w;
  }
}edge[MAXN*3];

inline void init(){
  for(int i=0;i<n;i++)pre[i]=i;
}

inline int find(int x){
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

inline void Union(int x,int y){
  pre[find(x)]=find(y);
}

inline void Kruskal(int& k){
  init();
  int i,sum=0;
  sort(edge,edge+k);
  for(i=0;i<k;i++){
    //printf("pre[x]=%d pre[y]=%d\n",find(edge[i].x),find(edge[i].y));
    if(find(edge[i].x)!=find(edge[i].y)){
      Union(edge[i].x,edge[i].y);
      sum+=edge[i].w;
      //printf("sum=%d\n",sum);
    }
  }
  printf("%d\n",sum);
}

int main(){
  int nn,k,m;
  char x[2],y[2];
  while(~scanf("%d",&n)&&n){
    nn=n,k=0;
    while((nn--)-1){
      scanf("%s%d",x,&m);
      while(m--){
        scanf("%s%d",y,&edge[k].w);
        edge[k].x=x[0]-'A';
        edge[k].y=y[0]-'A';
        //printf("edge[%d].x=%d edge[%d].y=%d\n",k,edge[k].x,k,edge[k].y);
        k++;
      }
    }
    Kruskal(k);
  }
}
