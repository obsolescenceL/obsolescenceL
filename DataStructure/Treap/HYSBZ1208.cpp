/*************************************************************************
     File Name: HYSBZ1208.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月04日 星期二 16时20分40秒
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
const int mod=1000000,INF=0x3f3f3f3f;
using namespace std;
struct treap{
  treap *l,*r;
  int v,fix,w,size;
  treap(int _v):v(_v){
    l=r=0;size=w=1;fix=rand();
  }
  int l_size(){return l? l->size:0;}
  int r_size(){return r? r->size:0;}
  void merger(){size=w;size+=l_size()+r_size();}
}*root;
int maxv,minv;

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
  //cout<<"--------------"<<endl;
  if(!p)p=new treap(v);
  else{
    if(p->v==v)p->w++;
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

void del(treap *&p,int v){
  if(p->v==v){
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

void find(treap *&p,int v){
  //cout<<"maxv="<<maxv<<endl;
  //cout<<"minv="<<minv<<endl;
  if(!p)return;
  if(p->v==v){
    minv=v,maxv=v;return;
  }else if(p->v > v){
    maxv=Min(maxv,p->v);
    find(p->l,v);
  }else{
    minv=Max(minv,p->v);
    find(p->r,v);
  }
}

int main(){
  int n,a,b,num=0,ans,sum=0;
  scanf("%d",&n);
  while(n--){
    scanf("%d%d",&a,&b);
    //cout<<"a="<<a<<" b="<<b<<endl;
    //cout<<"num="<<num<<endl;
    if(!num)
      insert(root,b),num++,ans=a;
    else if(ans==a)
      insert(root,b),num++;
    else{
      minv=-INF,maxv=INF;
      find(root,b);
      num--;
      int temp1=Abs(b,minv),temp2=Abs(b,maxv);
      if(temp1<=temp2){
        sum+=temp1;
        del(root,minv);
      }else{
        sum+=temp2;
        del(root,maxv);
      }
      sum%=mod;
      //cout<<"sum="<<sum<<endl;
    }
  }
  printf("%d\n",sum);
}
