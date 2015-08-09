/*************************************************************************
     File Name: POJ2985.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月09日 星期日 10时20分47秒
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
const int N=200010;
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
int pre[N],sum[N];

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
  else {
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

treap *find_kth(treap *&p,int k){
  if(k < p->l_size()+1)
    return find_kth(p->l,k);
  else if(k > p->l_size()+p->w)
    return find_kth(p->r,k-(p->l_size()+p->w));
  else return p;
}

int find(int x){
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

void Union(int x,int y){
  int fx=find(x),fy=find(y);
  //cout<<"fx="<<fx<<" fy="<<fy<<endl;
  if(fx!=fy){
    del(root,sum[fx]);
    //cout<<"-----------------"<<endl;
    del(root,sum[fy]);
    pre[fx]=fy;
    sum[fy]+=sum[fx];
    insert(root,sum[fy]);
  }
}

int main(){
  int n,m,op,i,x,y,k;
  while(~scanf("%d%d",&n,&m)){
    //cout<<"n="<<n<<" m="<<m<<endl;
    for(i=1;i<=n;++i)pre[i]=i,sum[i]=1,insert(root,1);
    while(m--){
      scanf("%d",&op);
      //cout<<"op="<<op<<endl;
      if(op){
        scanf("%d",&k);
        printf("%d\n",find_kth(root,root->size-k+1)->v);
      }else{
        scanf("%d%d",&x,&y);
        //cout<<"x="<<x<<" y="<<y<<endl;
        Union(x,y);
      }
    }
  }
}
