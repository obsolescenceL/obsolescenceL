/*************************************************************************
     File Name: HDU3726.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2014年08月10日 星期一 15时06分21秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stack>
#pragma comment(linker, "/STACK:102400000,102400000")
#define Mem0(x) memset(x,0,sizeof(x))
using namespace std;
const int N=2*1e4+10,M=4*1e5+10;
struct treap{
  treap *l,*r;
  int v,fix,size,w;
  treap(int _v,int _w):v(_v),w(_w){
    l=r=0;size=1;fix=rand();
  }
  int l_size(){return l? l->size:0;}
  int r_size(){return r? r->size:0;}
  void merger(){size=w+l_size()+r_size();}//!!!
}*root[N];

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

void insert(treap *&p,int v,int w){
  if(!p)p=new treap(v,w);
  else{
    if(p->v==v)p->w+=w;//!!!
    else if(p->v > v){
      insert(p->l,v,w);
      if(p->l->fix < p->fix)
        r_rotate(p);
    }else{
      insert(p->r,v,w);
      if(p->r->fix < p->fix)
        l_rotate(p);
    }
  }
  p->merger();
}

void del(treap *&p,int v){
  if(!p)return;
  if(p->v==v){
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
  if(k < p->l_size()+1)return find_kth(p->l,k);
  else if(k > p->l_size()+p->w)return find_kth(p->r,k-(p->l_size()+p->w));
  else return p;
}

void insert_tree(treap *&x,treap *&y){
  if(y->l)insert_tree(x,y->l);
  if(y->r)insert_tree(x,y->r);
  insert(x,y->v,y->w);//!!!
}

int val[N],n;
int pre[N],p1[M],p2[M];
bool delet[M];//!!!
struct node{
  char op;
  int x,k;
}t[M];

int find(int x){
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

void Union(int x,int y){
  x=find(x),y=find(y);
  if(x!=y)pre[y]=x;
}

int main(){
  int m,i,nc=0,x,v;
  char op[2];
  while(~scanf("%d%d",&n,&m)&&(n||m)){
    Mem0(root),Mem0(delet);
    for(i=1;i<=n;++i)
      scanf("%d",&val[i]),pre[i]=i;
    for(i=1;i<=m;++i)
      scanf("%d%d",&p1[i],&p2[i]);
    int op_n=0;//!!!
    while(~scanf("%s",op)){
      if(op[0]=='E')break;
      scanf("%d",&x);
      t[++op_n].op=op[0],t[op_n].x=x;
      if(op[0]=='D')delet[x]=1;
      else if(op[0]=='Q')
        scanf("%d",&t[op_n].k);
      else{
        scanf("%d",&v);
        t[op_n].k=val[x],val[x]=v;
      }
    }

    for(i=1;i<=m;++i)//!!!
      if(!delet[i])Union(p1[i],p2[i]);
    for(i=1;i<=n;++i)
      insert(root[find(i)],val[i],1);

    double sum=0;
    int cnt=0,t1,t2,temp;
    for(i=op_n;i>0;--i){
      if(t[i].op=='D'){
        t1=find(p1[t[i].x]);
        t2=find(p2[t[i].x]);
        if(t1==t2)continue;
        if(root[t1] && root[t2] && root[t1]->size > root[t2]->size){
          pre[t2]=t1;
          insert_tree(root[t1],root[t2]);
        }else if(root[t1] && root[t2]){
          pre[t1]=t2;
          insert_tree(root[t2],root[t1]);
        }
      }else if(t[i].op=='Q'){
        temp=find(t[i].x);
        cnt++;
        if(root[temp] && t[i].k>0 && t[i].k<=root[temp]->size){//!!!
          sum+=find_kth(root[temp],root[temp]->size-t[i].k+1)->v;
        }
      }else{
        temp=find(t[i].x);
        del(root[temp],val[t[i].x]);
        val[t[i].x]=t[i].k;
        insert(root[temp],val[t[i].x],1);
      }
    }
    printf("Case %d: ",++nc);
    if(!cnt)cnt++;//!!!
    printf("%.6lf\n",sum/cnt);
  }
}
