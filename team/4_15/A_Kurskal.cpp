/*************************************************************************
     File Name: A_Kurskal.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月15日 星期三 21时42分11秒
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
const int N=1001;
int n,m,k,pre[N],outlet[N];
struct Edge{
  int a,b,c;
  bool operator < (const Edge& rhs) const {
    return c<rhs.c;
  }
}edge[N*N/2];

inline void init(){
  for(int i=1;i<=n;++i)pre[i]=i;
}

inline int find(int x){
  return x==pre[x]?x:pre[x]=find(pre[x]);
}

inline void Union(int x,int y){
  pre[find(y)]=find(x);
}

inline void Kruskal(){
  int i,sum=0;
  init();
  sort(edge,edge+m+k-1);
  for(i=0;i<m+k-1;++i){
    if(find(edge[i].a)!=find(edge[i].b)){
      Union(edge[i].a,edge[i].b);
      sum+=edge[i].c;
    }
  }
  printf("%d\n",sum);
}

int main(){
  int i;
  while(~scanf("%d%d%d",&n,&m,&k)){
    for(i=0;i<k;++i){
      scanf("%d",outlet+i);
      if(i)edge[m+i-1].a=outlet[i-1],edge[m+i-1].b=outlet[i],edge[m+i-1].c=0;
    }
    for(i=0;i<m;++i)
      scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
    Kruskal();
  }
}
