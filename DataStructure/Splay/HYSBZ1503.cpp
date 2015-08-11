/*************************************************************************
     File Name: HYSBZ1503.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月11日 星期二 15时37分56秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<cstdlib>
#define ll long long
using namespace std;
struct node{
  int v,lazy,size,w;
  node *pre,*ch[2];
  node(){size=w=lazy=0;}
  *node(int _v):v(_v){
    ch[0]=ch[1]=0;
    size=w=1,lazy=0;
  }
  int l_size(){return ch[0]? ch[0]->size:0;}
  int r_size(){return ch[1]? ch[1]->size:0;}
  void merger(){
    size=w+l_size()+r_size();
    ch[0]->pre=ch[1]->pre=this;
  }
}*root,*last_vis,*root_pre,*Null;

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
  //cout<<"v="<<v<<endl;
  //if(p)cout<<"p->size="<<p->size<<endl;
  if(p==Null){
    p=new node(v);
    p->ch[0]=p->ch[1]=Null;
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

void splay(node *&last_vis,node *&root_pre){
  node *t=last_vis;
  while(t->pre != root_pre){
    if(t->pre->pre == root_pre){
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
  root=root_pre->ch[0];
}

node *q_succ(node *&p,int v){//include itself
  if(p==Null)return p;
  push_down(p);
  node *t;
  if(p->v == v)return p;
  else if(p->v < v)return q_succ(p->ch[1],v);
  else{
    t=q_succ(p->ch[0],v);
    if(t!=Null)return t;
    else return p;
  }
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
  Null=new node();root=Null;
  root_pre=new node();
  root_pre->ch[0]=root;
  root_pre->ch[1]=Null;
  root->pre=root_pre;
}

int main(){
  int n,minn,k,leave=0;
  char op[5];
  //root_pre->ch[0]=root;
  //root->pre=root_pre;
  pre();
  scanf("%d%d",&n,&minn);
  while(n--){
    scanf("%s%d",op,&k);
    //cout<<"op="<<op<<" k="<<k<<endl;
    if(op[0]=='I'){
      if(k>=minn){
        insert(root_pre->ch[0],k);
        root_pre->merger();
        splay(last_vis,root_pre);
        //cout<<"---------"<<endl;
      }
    }else if(op[0]=='A'){
      root->v+=k,root->lazy+=k;
    }else if(op[0]=='S'){
      last_vis=Null;
      last_vis=q_succ(root,minn+k);
      //cout<<"-------"<<endl;
      if(last_vis==Null){
        leave+=root->size;
        root=Null,root_pre->ch[0]=root;
        root_pre->merger();
      }else{
        splay(last_vis,root_pre);
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
