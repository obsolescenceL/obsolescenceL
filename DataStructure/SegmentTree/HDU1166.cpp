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
const int MAXN=50010;
int a[MAXN],ans,tree[MAXN<<2];

inline void build(int t,int L,int R){
  if(L==R){
    tree[t]=a[L];
    return;
  }
  for(int i=L;i<=R;++i)tree[t]+=a[i];
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
}

//void pull(int t,int l,int r){
//  if(tree[t].add&&t){
//    tree[t>>1].sum+=((l+r)<<1)*tree[t].add;
//    tree[t>>1].add=tree[t].add;
//    tree[t].add=0;
//    pull(t>>1,l,r);
//  }
//}
//
//void push(int t,int l,int r){
//  if(tree[t].add){
//    tree[t<<1].sum+=(((l+r)>>1+l)>>1)*tree[t].add;
//    tree[t<<1].add=tree[t].add;
//    tree[t<<1|1].sum+=(((l+r)>>1|1+r)>>1)*tree[t].add;
//    tree[t<<1|1].add=tree[t].add;
//    tree[t].add=0;
//    push(t<<1,l,(l+r)>>1);
//    push(t<<1|1,(l+r)>>1|1,r);
//  }
//}

inline void update(int t,int L,int R,int l,int r,int c){
  if(L==l&&R==r){
    tree[t]+=(R-L+1)*c;
    return;
  }
  //push(t,l,r);
  int mid=(R+L)>>1;
  if(r<=mid)update(t<<1,L,mid,l,r,c);
  else if(l>mid)update(t<<1|1,mid+1,R,l,r,c);
  else{
    update(t<<1,L,mid,l,r,c);
    update(t<<1|1,mid+1,R,l,r,c);
  }
  //pull(t,l,r);
  tree[t]=tree[t<<1]+tree[t<<1|1];
}

inline void query(int t,int L,int R,int l,int r){
  if(L==l&&R==r){
    //cout<<tree[t].sum<<endl;
    ans+=tree[t];
    return;
  }
  int mid=(R+L)>>1;
  if(r<=mid)query(t<<1,L,mid,l,r);
  else if(l>mid)query(t<<1|1,mid+1,R,l,r);
  else {
    query(t<<1,L,mid,l,mid);
    query(t<<1|1,mid+1,R,mid+1,r);
  }
}

int main(){
  int T,k,n,i,r,l;
  while(~scanf("%d",&T)){
    for(k=1;k<=T;++k){
      memset(tree,0,sizeof tree);
      printf("Case %d:\n",k);
      scanf("%d",&n);
      for(i=1;i<=n;++i) scanf("%d",a+i);
      build(1,1,n);
      char op[20];
      while(scanf("%s",op)){
        if(op[0]=='E')break;
        scanf("%d%d",&l,&r);
        if(op[0]=='Q'){
          ans=0;
          query(1,1,n,l,r);
          printf("%d\n",ans);
        }else if(op[0]=='A')update(1,1,n,l,l,r);
        else if(op[0]=='S')update(1,1,n,l,l,-r);
      }
    }
  }
}
