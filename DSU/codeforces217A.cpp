/*************************************************************************
     File Name: B.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月12日 15:23:14
 ************************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<iostream>
#include<cctype>
using namespace std;
struct Node{
  int x,y;
}node[110];
int nn,pre[110];

int find (int x){
  return x==pre[x]?x:pre[x]=find(pre[x]);
}

void Union(int x,int y){
  int fx=find(x),fy=find(y);
  if(fx!=fy){
    pre[fx]=fy;
    nn--;
  }
}

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    nn=n;
    for(i=0;i<110;++i)pre[i]=i;
    for(i=0;i<n;++i){
      scanf("%d%d",&node[i].x,&node[i].y);
      for(int j=0;j<i;++j)
        if(node[j].x==node[i].x||node[j].y==node[i].y)Union(i,j);
    }
    printf("%d\n",nn-1);
  }
}
