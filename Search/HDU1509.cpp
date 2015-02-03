/*************************************************************************
    > File Name: HDU1509.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 7日 20:56:00
 ************************************************************************/
#include<cstdio>
#include<string>
#include<queue>
#include<iostream>
using namespace std;
struct node{
  string s;
  int num,prior,id;
  node(string s,int num,int prior,int id):s(s),num(num),prior(prior),id(id) {}
  bool operator < (const node& node1) const{
    if(prior==node1.prior) return id>node1.id;
    return prior>node1.prior;
  }
};
int main() {
  string ss,op;
  int a,b,k=0;
  priority_queue<node>q;
  while(cin>>op){
    if(op=="PUT"){
      cin>>ss>>a>>b;
      q.push(node(ss,a,b,k++));
    }else{
      if(q.empty()) printf("EMPTY QUEUE!\n");
      else{
        cout<<q.top().s<<' '<<q.top().num<<'\n';
        q.pop();
      }
    }
  }
}
