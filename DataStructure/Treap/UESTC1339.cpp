/*************************************************************************
     File Name: I.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 三  4/20 21:26:36 2016
 ************************************************************************/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
struct treap{
  treap *l,*r;
  int v,fix,size;
  treap(int _v):v(_v){
    l=r=0,size=1;
    fix=rand();
  }
  int l_size(){return l?l->size:0;}
  int r_size(){return r?r->size:0;}
  void merger(){size=1+l_size()+r_size();}
}*root;

void l_rotate(treap *&x){
  treap *t=x->r;
  x->r=t->l;
  t->l=x;
  x->merger(),t->merger();
  x=t;
}

void r_rotate(treap *&x){
  treap *t=x->l;
  x->l=t->r;
  t->r=x;
  x->merger(),t->merger();
  x=t;
}

void insert(treap *&p,int v){
  if(!p) p=new treap(v);
  else{
    if(p->v > v){
      insert(p->l,v);
      if(p->l->fix < p->fix)
        r_rotate(p);
    }else{
      insert(p->r,v);
      if(p->r->fix < p->fix)
        l_rotate(p);
    }
  }
  p->merger();
}

void del(treap *&p,int v){
  if(p->v==v){
    if(!p->r || !p->l){
      if(!p->r)p=p->l;
      else p=p->r;
    }else{
      if(p->l->fix < p->r->fix){
        r_rotate(p);
        del(p->r,v);
      }else l_rotate(p),del(p->l,v);
    }
  }else if(p->v > v)del(p->l,v);
  else del(p->r,v);
  if(p)p->merger();
}

treap *find_kth(treap *&p,int k){
  if(k < p->l_size()+1)return find_kth(p->l,k);
  else if(k > p->l_size()+1)return find_kth(p->r,k-(p->l_size()+1));
  else return p;
}

int main(){
  int n,op,x;
  scanf("%d",&n);
  std::queue<int> q;
  bool f=1;
  while(n--){
    scanf("%d",&op);
    if(op==1){
      scanf("%d",&x);
      q.push(x);
      insert(root,x);
    }else if(op==2){
      x=q.front();q.pop();
      del(root,x);
    }else printf("%d\n",find_kth(root,root->size/2+1)->v);
  }
}
