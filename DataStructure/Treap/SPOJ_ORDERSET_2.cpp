/*************************************************************************
     File Name: SPOJ_ORDERSET.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月07日 星期五 09时33分02秒
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

int q_rank(treap *&p,int v,int cur){
  //cout<<"p->v="<<p->v<<endl;
  if(p->v == v)return p->l_size()+cur+1;
  else if(p->v > v)return q_rank(p->l,v,cur);
  else return q_rank(p->r,v,cur+p->l_size()+1);
}

treap *q_pred(treap *&p,int v,treap *optimal){
  if(!p)return optimal;
  if(p->v < v) return q_pred(p->r,v,p);
  else return q_pred(p->l,v,optimal);
}

int main(){
  int q,x;
  char op[2];
  srand(time(0));
  while(~scanf("%d",&q)){
    root=0;
    while(q--){
      //cout<<"num="<<num<<endl;
      scanf("%s%d",op,&x);
      //cout<<"op="<<op<<endl;
      if(op[0]=='I')insert(root,x);
      else  if(op[0]=='D')del(root,x);
      else if(op[0]=='C'){
        treap *optimal=q_pred(root,x,0);
        if(root && root->size && optimal){
          printf("%d\n",q_rank(root,optimal->v,0));
        }else puts("0");
      }else if(op[0]=='K'){
        if(root && root->size >= x)printf("%d\n",find_kth(root,x)->v);
        else puts("invalid");
      }
    }
  }
}
