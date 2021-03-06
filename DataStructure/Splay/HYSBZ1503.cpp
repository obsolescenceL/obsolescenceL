/*************************************************************************
     File Name: HYSBZ1503.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月11日 星期二 15时37分56秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
using namespace std;
struct node{
  int v,lazy,size,w;
  node *pre,*ch[2];
  node(){size=w=lazy=0;}
  *node(int _v):v(_v){size=w=1,lazy=0;}
  int l_size(){return ch[0]? ch[0]->size:0;}
  int r_size(){return ch[1]? ch[1]->size:0;}
  void merger(){
    size=w+l_size()+r_size();
    ch[0]->pre=ch[1]->pre=this;
  }
}*root,*last_vis,*Null;

int f(node *&p){
  return p->pre->ch[1] == p;
}

void zig(node *x,int to){//not *&x
  node *t=x->ch[to];
  t->pre=x->pre;
  x->pre->ch[f(x)]=t;
  //cout<<"---------"<<endl;
  x->ch[to]=t->ch[to^1];
  t->ch[to^1]=x;
  x->merger(),t->merger();
}

void push_down(node *&p){
  if(!p->lazy)return;
  p->ch[0]->v+=p->lazy;
  p->ch[0]->lazy+=p->lazy;
  p->ch[1]->v+=p->lazy;
  p->ch[1]->lazy+=p->lazy;
  p->lazy=0;
}

void insert(node *&p,int v){
  if(p==Null){
    p=new node(v);
    p->ch[0]=p->ch[1]=p->pre=Null;
    last_vis=p;
    //cout<<"p->v="<<p->v<<endl;
    return;
  }
  push_down(p);
  if(p->v == v)p->w++;
  else if(p->v > v)insert(p->ch[0],v);
  else insert(p->ch[1],v);
  p->merger();
}

void splay(node *&t,node *&goal){
  while(t->pre != goal){
    if(t->pre->pre == goal){
      zig(t->pre,f(t));
      //cout<<"---------"<<endl;
    }else if(f(t->pre) == f(t)){
      zig(t->pre->pre,f(t->pre));
      zig(t->pre,f(t));
    }else{
      zig(t->pre,f(t));
      zig(t->pre,f(t));
    }
  }
  if(goal==Null)root=t;
}

node *q_succ(node *&p,int v,node *optimal){
  if(p==Null)return optimal;
  push_down(p);
  if(p->v >= v)return q_succ(p->ch[0],v,p);
  else return q_succ(p->ch[1],v,optimal);
}

int find_kth(node *&p,int k){
  //cout<<"-------"<<endl;
  if(p==Null)return -1;
  push_down(p);
  if(k < p->r_size()+1)return find_kth(p->ch[1],k);
  else if(k > p->r_size()+p->w)
    return find_kth(p->ch[0],k-(p->r_size()+p->w));
  else return p->v;
}

void pre(){
  Null=new node();
  root=Null;root->pre=Null;
}

int main(){
  int n,minn,k,leave=0;
  char op[5];
  pre();
  scanf("%d%d",&n,&minn);
  while(n--){
    scanf("%s%d",op,&k);
    if(op[0]=='I'){
      if(k>=minn){
        insert(root,k);
        //cout<<"---------"<<endl;
        splay(last_vis,Null);
      }
    }else if(op[0]=='A'){
      root->v+=k,root->lazy+=k;
    }else if(op[0]=='S'){
      last_vis=Null;
      last_vis=q_succ(root,minn+k,Null);
      //cout<<"-------"<<endl;
      if(last_vis==Null){
        leave+=root->size;
        root=Null;
      }else{
        splay(last_vis,Null);
        leave+=root->l_size();
        root->ch[0]=Null;
        root->v-=k;
        root->lazy-=k;
        root->merger();
      }
    }else{
      printf("%d\n",find_kth(root,k));
    }
  }
  printf("%d\n",leave);
}
