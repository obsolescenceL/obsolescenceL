/*************************************************************************
     File Name: UESTC1073.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月23日 星期六 17时24分00秒
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
ll tree[N<<2];

void push_up(int t){
  tree[t]=tree[t<<1]+tree[t<<1|1];
}

void build(int t,int L,int R){
  if(L==R){
    scanf("%lld",&tree[t]);
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
  push_up(t);
}

void update(int t,int L,int R,int x,int v){
  if(L==R){
    tree[t]=v;
    return;
  }
  int mid=(L+R)>>1;
  if(x<=mid)update(t<<1,L,mid,x,v);
  else update(t<<1|1,mid+1,R,x,v);
  push_up(t);
}

ll query(int t,int L,int R,int l,int r){
  if(l<=L&&R<=r)return tree[t];
  int mid=(L+R)>>1;
  ll ans=0;
  if(l<=mid)ans+=query(t<<1,L,mid,l,r);
  if(r>mid)ans+=query(t<<1|1,mid+1,R,l,r);
  return ans;
}

int main(){
  int n,m,l,r,x,v,op;
  while(~scanf("%d",&n)){
    build(1,1,n);
    scanf("%d",&m);
    while(m--){
      scanf("%d",&op);
      if(op==1){
        scanf("%d%d",&x,&v);
        update(1,1,n,x,v);
      }else{
        scanf("%d%d",&l,&r);
        printf("%lld\n",query(1,1,n,l,r));
      }
    }
  }
}
