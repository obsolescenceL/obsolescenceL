/*************************************************************************
     File Name: I.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月28日 星期六 13时51分05秒
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
using namespace std;
const int M=200001;
struct Node{
  int pre,money;//pre代表父亲，money代表节点比根节点少多少钱
}node[M];

int find(int x){
  if(x!=node[x].pre){
    int pre=node[x].pre;
    node[x].pre=find(node[x].pre);
    node[x].money+=node[pre].money;
  }
  return node[x].pre;
}

void Union(int x,int y,int m){
  int fx=find(x),fy=find(y);
  if(fx!=fy){
    node[fy].pre=fx;
    node[fy].money=node[x].money+m-node[y].money;
  }
}

int main(){
  int n,a,b,m,i,op;
  while(~scanf("%d",&n)){
    for(i=0;i<=2*n;++i)node[i].pre=i,node[i].money=0;
    for(int nc=0;nc<n;++nc){
      scanf("%d",&op);
      if(op==1){
        scanf("%d%d%d",&a,&b,&m);
        Union(a,b,m);
      }else{
        scanf("%d%d",&a,&b);
        int fa=find(a),fb=find(b);
        if(fa!=fb)puts("?");//如果不在一个集合，说明无法比较
        else printf("%d\n",node[b].money-node[a].money);//输出的是都与根节点比较的差值
      }
      //for(i=1;i<=2*n;++i)cout<<"node["<<i<<"].pre="<<node[i].pre<<" money="<<node[i].money<<endl;
    }
  }
}
