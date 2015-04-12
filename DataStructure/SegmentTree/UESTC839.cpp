/*************************************************************************
     File Name: new4_8b.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月08日 星期三 19时49分00秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
using namespace std;
const int N=100001;
int a[N];
struct node{
  ll sum;
  int flag;//!!!
}tree[N<<2];

template<class T>//开挂
inline bool read(T &n){
  T x=0,tmp=1;
  char c=getchar();
  while((c<'0'||c>'9') && c!='-' && ~c)
    c=getchar();
  if(c==EOF)return 0;
  if(c=='-')c=getchar(),tmp=-1;
  while(c>='0' && c<='9')x*=10,x+=(c-'0'),c=getchar();
  n=x*tmp;
  return 1;
}
template<class T>
inline void write(T n){
  if(n<0)putchar('-'),n=-n;
  int len=0,data[20];
  while(n){
    data[len++]=n%10;
    n/=10;
  }
  if(!len)data[len++]=0;
  while(len--)putchar(data[len]+48);
}

inline void push_up(int t){
  tree[t].sum=tree[t<<1].sum+tree[t<<1|1].sum;
}

inline void push_down(int L,int R,int t){
  if(!tree[t].flag)return;
  int mid=(L+R)>>1;
  tree[t<<1].sum+=(ll)tree[t].flag*(mid-L+1);
  tree[t<<1|1].sum+=(ll)tree[t].flag*(R-mid);
  tree[t<<1].flag+=tree[t].flag;
  tree[t<<1|1].flag+=tree[t].flag;
  tree[t].flag=0;
}

inline void build(int t,int L,int R){//建树
  if(L==R){
    tree[t].sum=a[L];
    tree[t].flag=0;
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
  push_up(t);
}

inline void update(int t,int L,int R,int l,int r,int c){//区间更新
  if(l<=L&&R<=r){
    tree[t].sum+=(ll)(R-L+1)*c;//!!!!!  R-L+1  no r-l+1
    tree[t].flag+=c;
    return;
  }
  push_down(L,R,t);
  int mid=(R+L)>>1;
  if(l<=mid)update(t<<1,L,mid,l,r,c);
  if(r>mid)update(t<<1|1,mid+1,R,l,r,c);
  push_up(t);
}

inline ll query(int t,int L,int R,int l,int r){
  if(l<=L&&R<=r)return tree[t].sum;
  push_down(L,R,t);
  int mid=(R+L)>>1;
  ll ans=0;
  if(l<=mid)ans+=query(t<<1,L,mid,l,r);
  if(r>mid)ans+=query(t<<1|1,mid+1,R,l,r);
  return ans;
}

int main(){
  int n,i,r,l,m,w,op;
  ll ans;
  while(read(n)){
    read(m);
    memset(tree,0,sizeof tree);
    for(i=1;i<=n;++i)read(a[i]);
    build(1,1,n);
    while(m--){
      read(op);
      if(!op){
        read(l),read(r);
        ans=query(1,1,n,l,r);
        write(ans),puts("");
      }else{
        read(l),read(r),read(w);
        update(1,1,n,l,r,w);
      }
    }
  }
}
