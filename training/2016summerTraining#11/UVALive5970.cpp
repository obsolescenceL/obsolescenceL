/*************************************************************************
     File Name: I.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月04日 星期四 14时43分00秒
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
const int N=10010;
int num[N],s[N],n,m,q,vis[N],cnt[N],res_cnt;
ll ans[N],res;
struct Tree{
  ll sum;
  int c;
}tree[N<<2];
struct node{
  int s,e,id;
  bool operator < (const node &rhs) const {
    return e<rhs.e;
  }
}p[N*10];

void pushUp(int t) {
  tree[t].sum=tree[t<<1].sum+tree[t<<1|1].sum;
  tree[t].c=tree[t<<1].c+tree[t<<1|1].c;
}

void build(int t,int L,int R) {
  if (L==R) {
    tree[t].sum=num[L];
    tree[t].c=1;
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
  pushUp(t);
}

void update(int t,int L,int R,int x) {
  if (L==R) {
    tree[t].sum-=num[x];
    tree[t].c--;
    return;
  }
  int mid=(L+R)>>1;
  if (x<=mid) update(t<<1,L,mid,x);
  if (x>mid) update(t<<1|1,mid+1,R,x);
  pushUp(t);
}

void query(int t,int L,int R,int l,int r) {
  //cout<<"L="<<L<<" R="<<R<<endl;
  if (l<=L && R<=r) {
    res+=tree[t].sum;
    res_cnt+=tree[t].c;
    return;
  }
  int mid=(L+R)>>1;
  if (l<=mid) query(t<<1,L,mid,l,r);
  if (r>mid) query(t<<1|1,mid+1,R,l,r);
}

void solve() {
  int i,j=0;
  Mem0(vis);
  for (i=1; i<=n; ++i) {
    int pos=lower_bound(s+1,s+m+1,num[i])-s+1;
    if (vis[pos]) update(1,1,n,vis[pos]);
    vis[pos]=i;
    for (; j<q; ++j)
      if (p[j].e==i) {
        //cout<<"s="<<p[j].s<<" e="<<p[j].e<<endl;
        res=res_cnt=0;
        query(1,1,n,p[j].s,p[j].e);
        ans[p[j].id]=res;
        cnt[p[j].id]=res_cnt;
        //cout<<"ans["<<p[j].id<<"]="<<ans[p[j].id]<<" cnt["<<p[j].id<<"]="<<cnt[p[j].id]<<endl;
      } else break;
  }
}

int main() {
  int t,nc,i;
  while (~scanf("%d",&t)) {
    for (nc=1;nc<=t;++nc) {
      printf("Case %d:\n",nc);
      scanf("%d",&n);
      for (i=1; i<=n; ++i) {
        scanf("%d",num+i);
        s[i]=num[i];
      }
      build(1,1,n);
      m=1;
      sort(s+1,s+n+1);
      for (i=2; i<=n; ++i)
        if (s[i]!=s[i-1]) s[++m]=s[i];
      scanf("%d",&q);
      for (i=0; i<q; ++i) {
        scanf ("%d%d",&p[i].s,&p[i].e);
        p[i].id=i;
      }
      sort(p,p+q);
      solve();
      for (i=0; i<q; ++i) {
        /*if (cnt[i]) */printf("%.6lf\n",(double)ans[i]/cnt[i]);
        //else puts("0.000000");
      }
    }
  }
}
