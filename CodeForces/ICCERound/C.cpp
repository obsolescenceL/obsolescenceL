/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六 10/ 1 22:47:38 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#define lson t<<1
#define rson t<<1|1
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10;
typedef long long ll;
int pos[N],pos_pos[N];
ll a[N],pre[N];

struct node{
  ll sum;
  ll ln,rn;
  ll ls,rs,ms;
}tree[N<<2];

void pushUp(int t) {
  tree[t].sum=tree[lson].sum+tree[rson].sum;
  tree[t].ls=tree[lson].ls;
  tree[t].rs=tree[rson].rs;
  tree[t].ln=tree[lson].ln;
  tree[t].rn=tree[rson].rn;
  tree[t].ms=MAX(tree[lson].ms,tree[rson].ms);
  //cout<<"tree["<<t<<"].ms="<<tree[t].ms<<endl;
  if (tree[lson].rn>=0 && tree[rson].ln>=0) {
    if (tree[lson].ls==tree[lson].sum)
      tree[t].ls+=tree[rson].ls;
    if (tree[rson].rs==tree[rson].sum)
      tree[t].rs+=tree[lson].rs;
    tree[t].ms=MAX(tree[t].ms,tree[lson].rs+tree[rson].ls);
  }
  //cout<<"tree["<<t<<"].ms="<<tree[t].ms<<endl;
  //cout<<"tree["<<t<<"].sum="<<tree[t].sum<<endl;
}

void build(int t,int L,int R) {
  if (L==R) {
    tree[t].sum=tree[t].ls=tree[t].rs=tree[t].ms=tree[t].rn=tree[t].ln=a[L];
    return;
  }
  int mid=(L+R)>>1;
  build(lson,L,mid);
  build(rson,mid+1,R);
  pushUp(t);
}

void update(int t,int L,int R,int x,int c) {
  if (L==R) {
    tree[t].sum=tree[t].ls=tree[t].rs=tree[t].ms=tree[t].ln=tree[t].rn=c;
    return;
  }
  int mid=(L+R)>>1;
  if (x<=mid) update(lson,L,mid,x,c);
  else update(rson,mid+1,R,x,c);
  pushUp(t);
}

ll ans[N];

int main() {
  int n,i;
  cin>>n;
  MEM1(a);
  build(1,1,n);
  for (i=1; i<=n; ++i) {
    cin>>a[i];
  }
  for (i=1; i<=n; ++i) {
    cin>>pos[i];
    //pos_pos[pos[i]]=i;
  }
  ans[n+1]=0;
  for (i=n; i>1; --i) {
    //cout<<"pos_pos["<<i<<"]="<<pos_pos[i]<<" a="<<a[pos_pos[i]]<<endl;
    update(1,1,n,pos[i],a[pos[i]]);
    for (int j=1; j<=n*4; ++j)
      //cout<<"tree["<<j<<"].sum="<<tree[j].sum<<endl;
    ans[i]=tree[1].ms;
  }
  //cout<<tree[1].ms<<endl;
  for (i=2; i<=n+1; ++i)
    cout<<ans[i]<<endl;
}
