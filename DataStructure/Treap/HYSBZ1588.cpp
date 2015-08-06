/*************************************************************************
     File Name: HYSBZ1588.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月06日 星期四 13时00分21秒
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
const int INF=0x3f3f3f3f;
struct treap{
  treap *l,*r;
  int v,fix,w,size;
  treap(int _v):v(_v){
    l=r=0,size=w=1,fix=rand();
  }
  int l_size(){return l? l->size:0;}
  int r_size(){return r? r->size:0;}
  void merger(){size=w+l_size()+r_size();}
}*root;
int maxv,minv;

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
    if(p->v == v)p->w++;
    else if(p->v > v){
      insert(p->l,v);
      if(p->l->fix < p->fix)r_rotate(p);
    }else{
      insert(p->r,v);
      if(p->r->fix < p->fix)l_rotate(p);
    }
  }
  p->merger();
}

void find(treap *&p,int v){
  if(!p)return;
  if(p->v == v){
    minv=maxv=v;return;
  }else if(p->v > v){
    maxv=Min(maxv,p->v);
    find(p->l,v);
  }else{
    minv=Max(minv,p->v);
    find(p->r,v);
  }
}

int main(){
  int n,sum,i,x;
  while(~scanf("%d",&n)){
    root=0;
    for(i=0;i<n;++i){
      if(scanf("%d",&x)==EOF)x=0;
      minv=-INF,maxv=INF;
      find(root,x);
      if(i) sum+=Min(x-minv,maxv-x);
      else sum=x;
      insert(root,x);
      //cout<<"minv="<<minv<<" maxv="<<maxv<<endl;
    }
    printf("%d\n",sum);
  }
}
