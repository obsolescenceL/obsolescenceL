/*************************************************************************
     File Name: UESTC1057.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月22日 星期五 20时52分28秒
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
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=100001;
struct node{
  ll sum,add;
}tree[N<<2];

void push_up(int t){
  tree[t].sum=tree[t<<1].sum+tree[t<<1|1].sum;
}

void push_down(int t,int L,int R){
  if(!tree[t].add)return;
  int mid=(L+R)>>1;
  tree[t<<1].sum+=(ll)tree[t].add*(mid-L+1);
  tree[t<<1|1].sum+=(ll)tree[t].add*(R-mid);
  tree[t<<1].add+=tree[t].add;
  tree[t<<1|1].add+=tree[t].add;
  tree[t].add=0;
}

void build(int t,int L,int R){
  tree[t].add=0;
  if(L==R){
    scanf("%lld",&tree[t].sum);
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
  push_up(t);
}

void update(int t,int L,int R,int l,int r,int v){
  if(l<=L&&R<=r){
    tree[t].sum+=(ll)(R-L+1)*v;
    tree[t].add+=v;
    return;
  }
  push_down(t,L,R);
  int mid=(L+R)>>1;
  if(l<=mid)update(t<<1,L,mid,l,r,v);
  if(r>mid)update(t<<1|1,mid+1,R,l,r,v);
  push_up(t);
}

ll query(int t,int L,int R,int l,int r){
  if(l<=L&&R<=r)return tree[t].sum;
  push_down(t,L,R);
  int mid=(L+R)>>1;
  ll ans=0;
  if(l<=mid)ans+=query(t<<1,L,mid,l,r);
  if(r>mid)ans+=query(t<<1|1,mid+1,R,l,r);
  return ans;
}

int main(){
  int n,m,l,r,v;
  while(~scanf("%d",&n)){
    build(1,1,n);
    scanf("%d",&m);
    while(m--){
      scanf("%d%d%d",&l,&r,&v);
      update(1,1,n,l,r,v);
      printf("%lld\n",query(1,1,n,l,r));
    }
  }
}
