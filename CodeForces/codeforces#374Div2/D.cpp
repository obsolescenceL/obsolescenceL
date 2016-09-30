/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五  9/30 22:43:16 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N];
struct Tree{
  int pos;
  ll x;
}tree[N<<2];

void pushUp(int t) {
  if (tree[t<<1].x>tree[t<<1|1].x) {
    tree[t].x=tree[t<<1|1].x;
    tree[t].pos=tree[t<<1|1].pos;
  } else {
    tree[t].x=tree[t<<1].x;
    tree[t].pos=tree[t<<1].pos;
  }
}

void build(int t,int L,int R) {
  if (L==R) {
    if (a[L]>=0) tree[t].x=a[L];
    else tree[t].x=-a[L];
    tree[t].pos=L;
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
  pushUp(t);
}

void update(int t,int L,int R,int x,int v) {
  if (L==R && L==x) {
    tree[t].x+=v;
    return;
  }
  int mid=(L+R)>>1;
  if (x<=mid) update(t<<1,L,mid,x,v);
  else update(t<<1|1,mid+1,R,x,v);
  pushUp(t);
}

int main() {
  ios::sync_with_stdio(0);
  ll n,k,x;
  int i;
  while (cin>>n>>k>>x) {
    MEM0(tree);
    int cnt=0;
    for (i=1; i<=n; ++i) {
      cin>>a[i];
      if (a[i]<0) cnt++;
    }
    build(1,1,n);
    if (cnt%2) {
      while (k>0) {
        int tmp=tree[1].pos;
        if (a[tmp]>=0) a[tmp]+=x;
        else a[tmp]-=x;
        update(1,1,n,tmp,x);
        k--;
      }
    } else {
      int tmp=tree[1].pos;
      ll aa=a[tmp];
      while (k>0 && tree[1].x>=0) {
        if (a[tmp]>=0) aa+=-x;
        else aa-=-x;
        update(1,1,n,tmp,-x);
        k--;
      }
      a[tmp]=aa;
      //cout<<"k="<<k<<endl;
      update(1,1,n,tree[1].pos,-2*tree[1].x);
      while (k>0) {
        int tmp=tree[1].pos;
        if (a[tmp]>=0) a[tmp]+=x;
        else a[tmp]-=x;
        update(1,1,n,tmp,x);
        k--;
      }
    }
    for (i=1; i<=n; ++i)
      cout<<a[i]<<" \n"[i==n];
  }
}
