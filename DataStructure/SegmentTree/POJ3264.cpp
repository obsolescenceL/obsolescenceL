/*************************************************************************
     File Name: POJ3264.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月13日 星期一 10时01分03秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
using namespace std;
const int INF=0x3f3f3f3f;
const int N=50001;
int max_cow,min_cow;
struct node{
  int maxn,minn;
}tree[N<<2];

inline void push_up(int t){
  tree[t].maxn=Max(tree[t<<1].maxn,tree[t<<1|1].maxn);
  tree[t].minn=Min(tree[t<<1].minn,tree[t<<1|1].minn);
}

inline void build(int t,int L,int R){
  if(L==R){
    scanf("%d",&tree[t].maxn);
    tree[t].minn=tree[t].maxn;
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
  push_up(t);
}

inline void query(int t,int L,int R,int l,int r){
  if(L>=l&&R<=r){
    max_cow=Max(max_cow,tree[t].maxn);
    min_cow=Min(min_cow,tree[t].minn);
    return;
  }
  int mid=(R+L)>>1;
  if(l<=mid)query(t<<1,L,mid,l,r);
  if(r>mid)query(t<<1|1,mid+1,R,l,r);
}

int main(){
  int n,m,l,r,i;
  while(~scanf("%d%d",&n,&m)){
    build(1,1,n);
    while(m--){
      max_cow=0,min_cow=INF;
      scanf("%d%d",&l,&r);
      query(1,1,n,l,r);
      printf("%d\n",max_cow-min_cow);
    }
  }
}
