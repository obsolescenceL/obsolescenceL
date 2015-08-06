/*************************************************************************
     File Name: HYSBZ1503.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月05日 星期三 09时51分15秒
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

int minn,num,add,leave;

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

treap *find_kth(treap *&p,int k){
  if(k < p->l_size()+1)
    return find_kth(p->l,k);
  else if(k > p->l_size()+1)
    return find_kth(p->r,k-(p->l_size()+1));
  else return p;
}

treap *check(treap *&p){
  if(p){
    if(p->v + add < minn){
      p=check(p->r);
      if(p)p->merger();
    }else{
      p->l=check(p->l);
      if(p->l)p->l->merger();
    }
  }
  if(p)p->merger();
  return p;
}

int main(){
  int n,k;
  char op[5];
  scanf("%d%d",&n,&minn);
  while(n--){
    scanf("%s%d",op,&k);
    if(op[0]=='I'){
      if(k>=minn){
        insert(root,k-add);
        num++;
      }
    }else if(op[0]=='A'){
      add+=k;
    }else if(op[0]=='S'){
      add-=k;
      root=check(root);
      if(root){
        leave+=num-root->size;
        num=root->size;
      }else leave+=num,num=0;
    }else if(op[0]=='F'){
      if(k<=num)printf("%d\n",find_kth(root,num-k+1)->v+add);
      else puts("-1");
    }
  }
  printf("%d\n",leave);
}
