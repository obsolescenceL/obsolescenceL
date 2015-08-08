/*************************************************************************
     File Name: SPOJ_ORDERSET.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月07日 星期五 09时33分02秒
 ************************************************************************/
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
struct treap{
  treap *l,*r;
  int v,fix,size;
  treap(int _v):v(_v){
    l=r=0,size=1,fix=rand();
  }
  int l_size(){return l? l->size:0;}
  int r_size(){return r? r->size:0;}
  void merger(){size=1+l_size()+r_size();}
}*root;

void l_rotate(treap *&x){
  treap *t=x->r;
  x->r=t->l,t->l=x;
  x->merger(),t->merger();
  x=t;
}

void r_rotate(treap *&x){
  treap *t=x->l;
  x->l=t->r,t->r=x;
  x->merger(),t->merger();
  x=t;
}

void insert(treap *&p,int v){
  if(!p)p=new treap(v);
  else{
    if(p->v > v){
      insert(p->l,v);
      if(p->l->fix < p->fix)r_rotate(p);
    }else if(p->v < v){
      insert(p->r,v);
      if(p->r->fix < p->fix)l_rotate(p);
    }
  }
  p->merger();
}

void del(treap *&p,int v){
  if(!p)return;
  if(p->v == v){
    if(!p->r || !p->l){
      if(!p->r)p=p->l;
      else p=p->r;
    }else{
      if(p->l->fix < p->r->fix){
        r_rotate(p);
        del(p->r,v);
      }else{
        l_rotate(p);
        del(p->l,v);
      }
    }
  }else if(p->v  > v) del(p->l,v);
  else del(p->r,v);
  if(p)p->merger();
}

treap *find_kth(treap *&p,int k){
  if(k < p->l_size()+1)return find_kth(p->l,k);
  else if(k > p->l_size()+1)
    return find_kth(p->r,k-(p->l_size()+1));
  else return p;
}

int q_count(treap *&p,int v,int cnt){
  if(!p)return cnt;
  if(p->v > v)return q_count(p->l,v,cnt);
  else return q_count(p->r,v,cnt+p->l_size()+1);
}

int main(){
  int q,x;
  char op[2];
  srand(time(0));
  while(~scanf("%d",&q)){
    root=0;
    while(q--){
      scanf("%s%d",op,&x);
      if(op[0]=='I')insert(root,x);
      else  if(op[0]=='D')del(root,x);
      else if(op[0]=='C'){
        printf("%d\n",q_count(root,x-1,0));
      }else if(op[0]=='K'){
        if(root && root->size >= x)printf("%d\n",find_kth(root,x)->v);
        else puts("invalid");
      }
    }
  }
}
