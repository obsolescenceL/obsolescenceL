/*************************************************************************
    > File Name: HDU1873.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 7日 21:42:43
 ************************************************************************/
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct node{
  int id,p;
  friend bool operator < (node a,node b){
    if(a.p==b.p)return a.id>b.id;
    return a.p<b.p;
  }
}b;
int main(){
  int t,a;
  char op[10];
  while(~scanf("%d",&t)){
    int k=1;
    priority_queue<node>q[4];
    while(t--){
      scanf("%s",op);
      if(strcmp(op,"IN")==0){
        scanf("%d%d",&a,&b.p);
        q[a].push(node(p,k++));
        //printf("q[%d].size=%d\n",a,q[a].size());
      }else{
        scanf("%d",&a);
        if(q[a].empty())puts("EMPTY");
        else {
          printf("%d\n",q[a].top().id);
          q[a].pop();
        }
      }
    }
  }
}
