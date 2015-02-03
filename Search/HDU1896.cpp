/*************************************************************************
    > File Name: HDU1896.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 8日 10:09:36
 ************************************************************************/
#include<cstdio>
#include<queue>
using namespace std;
struct node{
  int pos,dis;
  node(int pos1,int dis1):pos(pos1),dis(dis1){}
  bool operator < (const node& node1)const{
    return pos>node1.pos || (pos==node1.pos && dis>node1.dis);
  }
};
int main(){
  int t,n,p,d;
  while(~scanf("%d",&t)){
    while(t--){
      priority_queue<node>q;
      scanf("%d",&n);
      for(int i=1;i<=n;i++){
        scanf("%d%d",&p,&d);
        q.push(node(p,d));
      }
      int sum=0;
      for(int i=1;i<=n;i++){
        if(i%2){
          sum=q.top().pos;
          d=q.top().dis;
          q.push(node(sum+d,d));
          q.pop();
          n++;
        }else{
          sum=q.top().pos;
          d=q.top().dis;
          q.pop();
        }
      }
      printf("%d\n",sum);
    }
  }
}
