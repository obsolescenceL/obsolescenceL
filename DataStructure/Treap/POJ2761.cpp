/*************************************************************************
     File Name: POJ2761.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月09日 星期日 15时31分36秒
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
  int v,fix,size,w;
  treap(int _v):v(_v){
    l=r=0,size=w=1,fix=rand();
  }
  int l_size(){return l? l->size:0;}
  int r_size(){return r? r->size:0;}
  void merger(){size=w+l_size()+r_size();}
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
    if(p->v == v)p->w++;
    else if(p->v > v){
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
  if(p->v == v){
    if(p->w > 1)p->w--;
    else if(!p->r || !p->l){
      if(p->l)p=p->l;
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

treap *find_kth(treap *&p,int k){
  //if(!p || k<=0 || k > p->size)return -1;
  if(k < p->l_size()+1)return find_kth(p->l,k);
  else if(k > p->l_size()+p->w)return find_kth(p->r,k-(p->l_size()+p->w));
  else return p;
}

const int N=100010,M=50010;
struct Query{
  int l,r,k,id;
  bool operator < (const Query& rhs) const {
    return l<rhs.l || (l==rhs.l && r<rhs.r);
  }
}q[M];
int val[N],ans[M];

int main(){
  int n,m,i;
  srand(time(0));//poj c++ zhici~
  while(~scanf("%d%d",&n,&m)){
    root=0;
    //cout<<"n="<<n<<" m="<<m<<endl;
    for(i=1;i<=n;++i)scanf("%d",val+i);
    for(i=1;i<=m;++i){
      scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k);
      q[i].id=i;
    }
    sort(q+1,q+m+1);
    int l=1,r=1;
    for(i=1;i<=m;++i){
      while(l<q[i].l){
        if(l<r)del(root,val[l]);
        l++;
      }
      if(r<l)r=l;
      while(r<=q[i].r){
        insert(root,val[r]);
        r++;
      }
      ans[q[i].id]=find_kth(root,q[i].k)->v;
    }
    for(i=1;i<=m;++i)printf("%d\n",ans[i]);
  }
}
