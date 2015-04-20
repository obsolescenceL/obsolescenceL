/*************************************************************************
     File Name: POJ3667.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月18日 星期六 18时41分40秒
 ************************************************************************/
#include<cstdio>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
using namespace std;
const int N=50001;
struct node{
  int lsum,rsum,sum,cover;
}tree[N<<2];

inline void update_cur(int t,int c,int n){
  tree[t].sum=tree[t].lsum=tree[t].rsum=(c^1)*n;
}

inline void push_up(int t,int n){
  tree[t].lsum=tree[t<<1].lsum;
  tree[t].rsum=tree[t<<1|1].rsum;
  if(tree[t].lsum==n-(n>>1))tree[t].lsum+=tree[t<<1|1].lsum;
  if(tree[t].rsum==(n>>1))tree[t].rsum+=tree[t<<1].rsum;
  tree[t].sum=Max(tree[t<<1|1].lsum+tree[t<<1].rsum,Max(tree[t<<1].sum,tree[t<<1|1].sum));
}

inline void push_down(int t,int n){
  if(tree[t].cover==-1)return;
  tree[t<<1].cover=tree[t<<1|1].cover=tree[t].cover;
  update_cur(t<<1,tree[t].cover,n-(n>>1));
  update_cur(t<<1|1,tree[t].cover,n>>1);
  tree[t].cover=-1;
}

inline void build(int t,int L,int R){
  tree[t].lsum=tree[t].rsum=tree[t].sum=R-L+1;
  tree[t].cover=-1;
  if(L==R)return;
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
}

inline void update(int t,int L,int R,int l,int r,int c){
  if(l<=L&&R<=r){
    tree[t].cover=c;
    update_cur(t,c,R-L+1);
    return;
  }
  push_down(t,R-L+1);
  int mid=(L+R)>>1;
  if(l<=mid)update(t<<1,L,mid,l,r,c);
  if(r>mid)update(t<<1|1,mid+1,R,l,r,c);
  push_up(t,R-L+1);
}

inline int query(int t,int L,int R,int a){
  if(L==R)return 1;
  push_down(t,R-L+1);
  int mid=(L+R)>>1;
  if(tree[t<<1].sum>=a)return query(t<<1,L,mid,a);
  else if(tree[t<<1].rsum+tree[t<<1|1].lsum>=a)return mid-tree[t<<1].rsum+1;
  return query(t<<1|1,mid+1,R,a);
}

int main(){
  int n,m,a,b,op;
  while(~scanf("%d%d",&n,&m)){
    build(1,1,n);
    while(m--){
      scanf("%d",&op);
      if(op==1){
        scanf("%d",&a);
        if(tree[1].sum<a)puts("0");
        else{
          int ans=query(1,1,n,a);
          printf("%d\n",ans);
          update(1,1,n,ans,ans+a-1,1);
        }
      }else{
        scanf("%d%d",&a,&b);
        update(1,1,n,a,a+b-1,0);
      }
    }
  }
}
