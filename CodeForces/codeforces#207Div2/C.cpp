/*************************************************************************
     File Name: C.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月29日 星期五 10时50分59秒
 ************************************************************************/
#include<bits/stdc++.h>
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
const int N=3*1e5+10;
struct T{
 int x,flag;
}tree[N<<2];
struct node{
  int l,r,x;
}q[N];

void pushDown(int t) {
  if (!tree[t].flag) return;
  tree[t<<1].x=tree[t<<1].flag=tree[t].flag;
  tree[t<<1|1].x=tree[t<<1|1].flag=tree[t].flag;
  tree[t].flag=0;
}

void update(int t,int L,int R,int l,int r,int c) {
  if (l>r) return;
  if (l<=L && R<=r) {
    tree[t].x=c;
    tree[t].flag=c;
    return;
  }
  int mid=(L+R)>>1;
  pushDown(t);
  if (l<=mid) update(t<<1,L,mid,l,r,c);
  if (r>mid) update(t<<1|1,mid+1,R,l,r,c);
}

int query(int t,int L,int R,int x) {
  if (L==R) {
    if (tree[t].x==L) return 0;
    return tree[t].x;
  }
  int mid=(L+R)>>1;
  pushDown(t);
  if (x<=mid) query(t<<1,L,mid,x);
  else query(t<<1|1,mid+1,R,x);
}

int main() {
  int n,m,i;
  while (~scanf("%d%d",&n,&m)) {
    Mem0(tree);
    for (i=0; i<m; ++i)
      scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].x);
    for (i=m-1; i>=0; --i) {
      update(1,1,n,q[i].l,q[i].x-1,q[i].x);
      update(1,1,n,q[i].x+1,q[i].r,q[i].x);
    }
    for (i=1; i<=n; ++i)
      printf("%d%c",query(1,1,n,i),i==n? '\n':' ');
  }
}
