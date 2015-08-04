/*************************************************************************
     File Name: HYSBZ3224.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月03日 星期一 10时25分30秒
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
struct Node{
  Node *left,*right;
  int v,fix,w,size;
  Node(int _v):v(_v){
    left=right=0;
    size=w=1;
    fix=rand();
  }
  int l_size(){return left? left->size:0;}
  int r_size(){return right? right->size:0;}
  void merger(){size=w;size+=l_size()+r_size();}
}*root;

void left_rotate(Node *&x){
  Node *t=x->right;
  x->right=t->left;
  t->left=x;
  x->merger();
  t->merger();
  x=t;
}

void right_rotate(Node *&x){
  Node *t=x->left;
  x->left=t->right;
  t->right=x;
  x->merger();
  t->merger();
  x=t;
}

void insert(Node *&p,int v){
  //cout<<"v="<<v<<endl;
  //if(p)cout<<"p->v="<<p->v<<endl;
  if(!p) p=new Node(v);
  else{
    if(p->v==v)p->w++;
    else if(p->v > v){
      insert(p->left,v);
      if(p->left->fix < p->fix)
        right_rotate(p);
    }else{
      insert(p->right,v);
      if(p->right->fix < p->fix)
        left_rotate(p);
    }
  }
  p->merger();
}

void del(Node *&p,int v){
  if(p->v==v){
    if(p->w > 1)p->w--;
    else if(!p->right || !p->left){
      //Node *t=p;
      if(!p->right)p=p->left;
      else p=p->right;
      //delete t;
    }else{
      if(p->left->fix < p->right->fix){
        right_rotate(p);
        del(p->right,v);
      }else{
        left_rotate(p);
        del(p->left,v);
      }
    }
  }else if(p->v > v)del(p->left,v);
  else del(p->right,v);
  if(p)p->merger();
}

Node *q_pred(Node *&p,int v,Node *optimal){
  if(!p)return optimal;
  if(p->v < v)return q_pred(p->right,v,p);
  else return q_pred(p->left,v,optimal);
}

Node *q_succ(Node *&p,int v,Node *optimal){
  if(!p)return optimal;
  if(p->v > v)return q_succ(p->left,v,p);
  else return q_succ(p->right,v,optimal);
}

Node *find_kth(Node *&p,int k){
  //cout<<"p->v="<<p->v<<endl;
  if(k < p->l_size()+1)
    return find_kth(p->left,k);
  else if(k > p->l_size()+p->w)
    return find_kth(p->right,k-(p->l_size()+p->w));
  else return p;
}

int q_rank(Node *&p,int v,int cur){
  if(p->v==v)return p->l_size()+cur+1;
  else if(p->v > v)return q_rank(p->left,v,cur);
  else return q_rank(p->right,v,cur+p->l_size()+p->w);
}

int main(){
  int n,i,op,x;
  srand(time(0));//HYSBZ不支持此函数
  scanf("%d",&n);
  while(n--){
    scanf("%d%d",&op,&x);
    //cout<<"op="<<op<<endl;
    switch(op){
      case 1: insert(root,x);break;
      case 2: del(root,x);break;
      case 3: printf("%d\n",q_rank(root,x,0));break;
      case 4: printf("%d\n",find_kth(root,x)->v);break;
      case 5: printf("%d\n",q_pred(root,x,0)->v);break;
      case 6: printf("%d\n",q_succ(root,x,0)->v);break;
    }
  }
}
