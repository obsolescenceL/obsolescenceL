/*************************************************************************
     File Name: HYSBZ1588.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月11日 星期二 21时49分12秒
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
#define Min(x,y) ((x)<(y)?(x):(y))
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
using namespace std;
const int INF=0x3f3f3f3f;
struct node{
  node *pre,*ch[2];
  int v,size,w;
  node(){size=w=0;}
  *node(int _v):v(_v){
    ch[0]=ch[1]=pre=0;
    size=w=1;
  }
  int l_size(){return ch[0]?ch[0]->size:0;}
  int r_size(){return ch[1]?ch[1]->size:0;}
  void merger(){
    size=w+l_size()+r_size();
    ch[0]->pre=ch[1]->pre=this;
  }
  int f(){return this->pre->ch[1]==this;}
}*root,*last_vis,*Null;

void rotate(node *x,int to){
  node *t=x->ch[to];
  t->pre=x->pre;
  x->pre->ch[x->f()]=t;
  x->ch[to]=t->ch[to^1];
  t->ch[to^1]=x;
  x->merger(),t->merger();
}

void splay(node *&t,node *&goal){
  while(t->pre != goal){
    if(t->pre->pre == goal){
      //cout<<"------------"<<endl;
      rotate(t->pre,t->f());
    }else if(t->pre->f() == t->f()){
      //cout<<"------------"<<endl;
      rotate(t->pre->pre,t->pre->f());
      rotate(t->pre,t->f());
    }else{
      //cout<<"------------"<<endl;
      rotate(t->pre,t->f());
      rotate(t->pre,t->f());
    }
  }
  if(goal==Null)root=t;
}

void insert(node *&p,int v){
  if(p==Null){
    p=new node(v);
    p->ch[0]=p->ch[1]=p->pre=Null;
    last_vis=p;
    return;
  }
  if(p->v==v)p->w++;
  else if(p->v > v)insert(p->ch[0],v);
  else insert(p->ch[1],v);
  p->merger();
}

int q_pred(node *&p,int v,int optimal){
  if(p==Null)return optimal;
  if(p->v <= v)return q_pred(p->ch[1],v,p->v);
  else return q_pred(p->ch[0],v,optimal);
}

int q_succ(node *&p,int v,int optimal){
  if(p==Null)return optimal;
  if(p->v >= v)return q_succ(p->ch[0],v,p->v);
  else return q_succ(p->ch[1],v,optimal);
}

void init(){
  Null=new node();root=Null;
  root->pre=Null;
}

int main(){
  int n,sum,i,x,t1,t2;
  while(~scanf("%d",&n)){
    init();
    for(i=0;i<n;++i){
      if(scanf("%d",&x)==EOF)x=0;
      //cout<<"x="<<x<<endl;
      if(i){
        t1=q_pred(root,x,INF);
        t2=q_succ(root,x,INF);
        sum+=Min(Abs(x,t1),Abs(t2,x));
        //cout<<"sum="<<sum<<endl;
        //cout<<"!!! "<<t1<<" "<<t2<<endl;
      }else sum=x;

      //insert(x);
      insert(root,x);
      //cout<<"------------"<<endl;
      splay(last_vis,Null);
    }
    printf("%d\n",sum);
  }
}
