/*************************************************************************
     File Name: UESTC844.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月04日 星期一 21时14分39秒
 ************************************************************************/
#include<cstdio>
#define Max(x,y) ((x)>(y)?(x):(y))
#define lson t<<1
#define rson t<<1|1
const int N=100001,INF=0x3f3f3f3f;
struct node{
  int sum,l_s,r_s,max_s;
}T[N<<2];

inline void push_up(int t){
  T[t].sum=T[lson].sum+T[rson].sum;
  T[t].l_s=Max(T[lson].l_s,T[lson].sum+T[rson].l_s);
  T[t].r_s=Max(T[rson].r_s,T[rson].sum+T[lson].r_s);
  T[t].max_s=Max(T[lson].r_s+T[rson].l_s,Max(T[lson].max_s,T[rson].max_s));
}

inline void build(int t,int L,int R){
  if(L==R){
    scanf("%d",&T[t].sum);
    T[t].l_s=T[t].r_s=T[t].max_s=T[t].sum;
    return;
  }
  int mid=(L+R)>>1;
  build(lson,L,mid);
  build(rson,mid+1,R);
  push_up(t);
}

inline void update(int t,int L,int R,int x,int w){
  if(L==R){
    T[t].sum=T[t].l_s=T[t].r_s=T[t].max_s=w;
    return;
  }
  int mid=(L+R)>>1;
  if(x<=mid)update(lson,L,mid,x,w);
  else update(rson,mid+1,R,x,w);
  push_up(t);
}

inline node query(int t,int L,int R,int l,int r){
  if(l<=L&&R<=r)return T[t];
  int mid=(L+R)>>1;
  node lnode,rnode,ans;
  ans.max_s=-INF;
  if(l<=mid)ans=lnode=query(lson,L,mid,l,r);
  if(r>mid)ans=rnode=query(rson,mid+1,R,l,r);
  if(l<=mid&&r>mid){
    ans.sum=lnode.sum+rnode.sum;
    ans.l_s=Max(lnode.l_s,lnode.sum+rnode.l_s);
    ans.r_s=Max(rnode.r_s,rnode.sum+lnode.r_s);
    ans.max_s=Max(lnode.r_s+rnode.l_s,Max(lnode.max_s,rnode.max_s));
  }
  return ans;
}

int main(){
  int n,m,i,op,l,r,x,w;
  while(~scanf("%d%d",&n,&m)){
    build(1,1,n);
    while(m--){
      scanf("%d",&op);
      if(op){
        scanf("%d%d",&x,&w);
        update(1,1,n,x,w);
      }else{
        scanf("%d%d",&l,&r);
        printf("%d\n",query(1,1,n,l,r).max_s);
      }
    }
  }
}
