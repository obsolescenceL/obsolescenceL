/*************************************************************************
     File Name: f.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月18日 星期六 20时26分53秒
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
#define ll long long
using namespace std;
const int N=100010;
struct Node{
  int pre,w;
}node[N];

int find(int x){
  if(x!=node[x].pre){
    int pre=node[x].pre;
    node[x].pre=find(node[x].pre);
    node[x].w+=node[pre].w;
  }
  return node[x].pre;
}

void Union(int x,int y,int w){
  int fx=find(x),fy=find(y);
  if(fx!=fy){
    node[fy].pre=fx;
    node[fy].w=node[x].w+w-node[y].w;
  }
}

int main(){
  int n,m,i,a,b,w;
  char op[2];
  while(~scanf("%d%d",&n,&m)&&(n||m)){
    for(i=0;i<=n;++i)node[i].pre=i,node[i].w=0;
    while(m--){
      scanf("%s",op);
      if(op[0]=='!'){
        scanf("%d%d%d",&a,&b,&w);
        Union(a,b,w);
      }else{
        scanf("%d%d",&a,&b);
        if(find(a)!=find(b))puts("UNKNOWN");
        else printf("%d\n",node[b].w-node[a].w);
      }
    }
  }
}
