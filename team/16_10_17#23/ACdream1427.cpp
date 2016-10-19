/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一 10/17 13:32:50 2016
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
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e5+10,INF=0x3f3f3f3f;
int cnt[N],tree[N<<2],ans,x[N];

void pushUp(int t) {
  tree[t]=MIN(tree[t<<1],tree[t<<1|1]);
  //cout<<"tree["<<t<<"]="<<tree[t]<<endl;
}

void update(int t,int L,int R,int x) {
  //cout<<"L="<<L<<" R="<<R<<endl;
  if (L==R && L==x) {
    tree[t]++;
    return;
  }
  int mid=(L+R)>>1;
  if (x<=mid) update(t<<1,L,mid,x);
  else update(t<<1|1,mid+1,R,x);
  pushUp(t);
}

void query(int t,int L,int R,int l,int r) {
  if (l<=L && R<=r) {
    ans=MIN(ans,tree[t]);
    return;
  }
  int mid=(L+R)>>1;
  if (l<=mid) query(t<<1,L,mid,l,r);
  if(r>mid) query(t<<1|1,mid+1,R,l,r);
}

int main() {
  //freopen("nice.in","r",stdin);
  //freopen("nice.out","w",stdout);
  int n,k,res,i;
  while (~scanf("%d%d",&n,&k)) {
    MEM0(tree),MEM0(cnt);
    res=n;
    for (i=1; i<=n; ++i) scanf("%d",x+i);
    for (i=1; i<=n; ++i) {
      x[i]++;
      //cout<<"x="<<x<<endl;
      cnt[x[i]]++;
      update(1,1,n+1,x[i]);
      ans=INF;
      query(1,1,n+1,1,x[i]);
      //cout<<"ans="<<ans<<endl;
      if (cnt[x[i]]>ans+k) {
        res=i-1;
        break;
      }
    }
    printf("%d\n",res);
  }
}
