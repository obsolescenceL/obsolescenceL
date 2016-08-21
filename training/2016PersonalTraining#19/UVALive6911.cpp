/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日  8/21 14:18:12 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=100010,M=1000010;
struct node{
  int a,b,c;
  bool operator < (const node &rhs) const {
    return c < rhs.c;
  }
}sword[N];
int tree[M<<2],cnt;

void push_up(int t) {
  tree[t]=tree[t<<1]+tree[t<<1|1];
}

void update(int t,int L,int R,int x,int v) {
  if (L==R) {
    tree[t]+=v;
    return;
  }
  int mid=(L+R)>>1;
  if (x<=mid) update(t<<1,L,mid,x,v);
  else update(t<<1|1,mid+1,R,x,v);
  push_up(t);
}

void query(int t,int L,int R,int l,int r) {
  if (l<=L && R<=r) {
    cnt+=tree[t];
    return;
  }
  int mid=(L+R)>>1;
  if (l<=mid) query(t<<1,L,mid,l,r);
  if (r>mid) query(t<<1|1,mid+1,R,l,r);
}

int main() {
  int t,i,n,m;
  while (~scanf("%d",&t)) {
    for (int nc=1; nc<=t; ++nc) {
      printf("Case #%d: ",nc);
      scanf("%d",&n);
      m=0, MEM0(tree);
      for (i=0; i<n; ++i) {
        scanf("%d%d%d",&sword[i].a,&sword[i].b,&sword[i].c);
        m=MAX(sword[i].a,m);
        m=MAX(sword[i].b,m);
        m=MAX(sword[i].c,m);
      }
      for (i=0; i<n; ++i) {
        cnt=0;
        query(1,1,m,sword[i].a,sword[i].a);
        if (!cnt) update(1,1,m,sword[i].a,1);
      }
      sort(sword,sword+n);
      for (i=0; i<n; ++i) {
        int a=sword[i].a,l=sword[i].b,r=sword[i].c;
        cnt=0;
        query(1,1,m,l,r);
        if (!cnt) update(1,1,m,r,1);
        else if (cnt==1 && l<=a && a<=r)
          update(1,1,m,r,1);
      }
      printf("%d\n",tree[1]);
    }
  }
}
