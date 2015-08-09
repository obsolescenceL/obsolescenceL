/*************************************************************************
     File Name: POJ3481.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月09日 星期日 14时22分52秒
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
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
struct treap{
  treap *l,*r;
  int v,fix,size,id;
  treap(int _v,int _id):v(_v),id(_id){
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

void insert(treap *&p,int v,int id){
  if(!p)p=new treap(v,id);
  else{
    if(p->v > v){
      insert(p->l,v,id);
      if(p->l->fix < p->fix)
        r_rotate(p);
    }else {
      insert(p->r,v,id);
      if(p->r->fix < p->fix)
        l_rotate(p);
    }
  }
  p->merger();
}

void del(treap *&p,int v){
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
  }else if(p->v > v)del(p->l,v);
  else del(p->r,v);
  if(p)p->merger();
}

treap *find_max(treap *&p){
  if(p->r)return find_max(p->r);
  return p;
}

treap *find_min(treap *&p){
  if(p->l)return find_min(p->l);
  return p;
}

int main(){
  int op,x,id;
  while(~scanf("%d",&op)&&op){
    if(op==1){
      scanf("%d%d",&id,&x);
      insert(root,x,id);
    }else if(op==2){
      if(root){
        treap *t=find_max(root);
        printf("%d\n",t->id);
        del(root,t->v);
      }else puts("0");
    }else if(op==3){
      if(root){
        treap *t=find_min(root);
        printf("%d\n",t->id);
        del(root,t->v);
      }else puts("0");
    }
  }
}
