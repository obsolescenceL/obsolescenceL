/*************************************************************************
     File Name: HDU1166.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月 5日  9:16:48
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=50010;
int a[N];
struct node{
  int sum,add;
}tree[N<<2];

inline void push_up(int t){
  tree[t].sum=tree[t<<1].sum+tree[t<<1|1].sum;
}

inline void push_down(int t,int L,int R){
  if(!tree[t].add)return;
  int mid=(L+R)>>1;
  tree[t<<1].sum+=tree[t].add*(mid-L+1);
  tree[t<<1|1].sum+=tree[t].add*(R-mid);
  tree[t<<1].add+=tree[t].add;
  tree[t<<1|1].add+=tree[t].add;
  tree[t].add=0;
}

inline void build(int t,int L,int R){
  if(L==R){
    tree[t].sum=a[L];
    tree[t].add=0;
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
  push_up(t);
}

inline void update(int t,int L,int R,int l,int r,int c){
  if(L>=l&&R<=r){
    tree[t].sum+=(R-L+1)*c;
    tree[t].add+=c;
    return;
  }
  push_down(t,L,R);
  int mid=(R+L)>>1;
  if(l<=mid)update(t<<1,L,mid,l,r,c);
  if(r>mid)update(t<<1|1,mid+1,R,l,r,c);
  push_up(t);
}

inline int query(int t,int L,int R,int l,int r){
  if(L>=l&&R<=r) return tree[t].sum;
  push_down(t,L,R);
  int mid=(R+L)>>1;
  int ans=0;
  if(l<=mid)ans+=query(t<<1,L,mid,l,r);
  if(r>mid)ans+=query(t<<1|1,mid+1,R,l,r);
  return ans;
}

int main(){
  int T,k,n,i,r,l;
  char op[20];
  while(~scanf("%d",&T)){
    for(k=1;k<=T;++k){
      memset(tree,0,sizeof tree);
      printf("Case %d:\n",k);
      scanf("%d",&n);
      for(i=1;i<=n;++i) scanf("%d",a+i);
      build(1,1,n);
      while(scanf("%s",op)){
        if(op[0]=='E')break;
        scanf("%d%d",&l,&r);
        if(op[0]=='Q'){
          printf("%d\n",query(1,1,n,l,r));
        }else if(op[0]=='A')update(1,1,n,l,l,r);
        else if(op[0]=='S')update(1,1,n,l,l,-r);
      }
    }
  }
}
