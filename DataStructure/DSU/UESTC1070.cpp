/*************************************************************************
     File Name: UESTC1070.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月23日 星期六 19时37分12秒
 ************************************************************************/
#include<cstdio>
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
const int N=100005,mod=1000;
struct Node{
  int pre;
  ll dis;
}node[N];

int Find(int x){
  if(x!=node[x].pre){
    int pre=node[x].pre;
    node[x].pre=Find(node[x].pre);
    node[x].dis+=node[pre].dis;
  }
  return node[x].pre;
}

void Union(int x,int y){
  int fy=Find(y),w=Abs(x,y)%mod;
  if(x!=fy){
    node[x].pre=fy;
    node[x].dis=node[y].dis+w;
  }
}

int main(){
  int x,y,n,i;
  char op[2];
  while(~scanf("%d",&n)){
    for(i=0;i<=n;i++)
      node[i].pre=i,node[i].dis=0;
    while(scanf("%s",op)&&op[0]!='O'){
      if(op[0]=='I'){
        scanf("%d%d",&x,&y);
        Union(x,y);
      }else{
        scanf("%d",&x);
        Find(x);
        printf("%lld\n",node[x].dis);
      }
    }
  }
}
