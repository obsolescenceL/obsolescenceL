/*************************************************************************
     File Name: HDU1698.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月16日 星期四 15时34分03秒
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
using namespace std;
const int N=100001;
struct node{
  int sum,add;
}tree[N<<2];

inline void push_up(int t){
  tree[t].sum=tree[t<<1].sum+tree[t<<1|1].sum;
}

inline void push_down(int t,int L,int R){
  if(!tree[t].add)return;
  int mid=(L+R)>>1;
  tree[t<<1].sum=tree[t].add*(mid-L+1);
  tree[t<<1|1].sum=tree[t].add*(R-mid);
  tree[t<<1].add=tree[t].add;
  tree[t<<1|1].add=tree[t].add;
  tree[t].add=0;
}

inline void build(int t,int L,int R){
  if(L==R){
    tree[t].sum=1;
    tree[t].add=0;
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
  push_up(t);
}

inline void update(int t,int L,int R,int l,int r,int c){
  if(l<=L&&R<=r){
    //if(c==tree[t].add)return;
    tree[t].sum=(R-L+1)*c;
    tree[t].add=c;
    return;
  }
  push_down(t,L,R);
  int mid=(L+R)>>1;
  if(l<=mid)update(t<<1,L,mid,l,r,c);
  if(r>mid)update(t<<1|1,mid+1,R,l,r,c);
  push_up(t);
}

int main(){
  int t,n,q,l,r,c;
  while(~scanf("%d",&t)){
    for(int nc=1;nc<=t;++nc){
      memset(tree,0,sizeof tree);
      scanf("%d%d",&n,&q);
      build(1,1,n);
      while(q--){
        scanf("%d%d%d",&l,&r,&c);
        update(1,1,n,l,r,c);
      }
      printf("Case %d: The total value of the hook is %d.\n",nc,tree[1].sum);
    }
  }
}
