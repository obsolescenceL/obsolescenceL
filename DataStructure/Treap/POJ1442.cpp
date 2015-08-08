/*************************************************************************
     File Name: POJ1442.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月08日 星期六 17时22分56秒
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
  x->r=t->l;
  t->l=x;
  x->merger();
  t->merger();
  x=t;
}

void r_rotate(treap *&x){
  treap *t=x->l;
  x->l=t->r;
  t->r=x;
  x->merger();
  t->merger();
  x=t;
}

void insert(treap *&p,int v){
  //if(p)cout<<"p->v="<<p->v<<endl;
  if(!p)p=new treap(v);
  else{
    if(p->v==v)p->w++;
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

treap *find_kth(treap *&p,int k){
  //if(p)cout<<"p->v="<<p->v<<endl;
  if(k < p->l_size()+1)
    return find_kth(p->l,k);
  else if(k > p->l_size()+p->w)
    return find_kth(p->r,k-(p->l_size()+p->w));
  else return p;
}

const int N=30010;
int add[N],get[N];

int main(){
  int n,m,i,j,k;
  //srand(time(0));
  while(~scanf("%d%d",&n,&m)){
    root=0;
    for(i=1;i<=n;++i)scanf("%d",add+i);
    for(i=1;i<=m;++i)scanf("%d",get+i);
    for(i=j=1,k=0;i<=n;++i){
      insert(root,add[i]);
      //cout<<"add["<<i<<"]="<<add[i]<<endl;
      while(j<=m && i==get[j]){
        j++;
        printf("%d\n",find_kth(root,++k)->v);
        //cout<<"k="<<k<<endl;
      }
    }
  }
}
