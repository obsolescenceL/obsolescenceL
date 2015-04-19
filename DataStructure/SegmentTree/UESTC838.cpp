/*************************************************************************
     File Name: UESTC838.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月19日 星期日 20时35分31秒
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
using namespace std;
const int N=100001;
int tree[N<<2];

inline void push_up(int t){
  tree[t]=tree[t<<1]+tree[t<<1|1];
}

inline void build(int t,int L,int R){
  if(L==R){
    scanf("%d",&tree[t]);
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
  push_up(t);
}

inline void update(int t,int L,int R,int x,int c){
  if(L==R){
    tree[t]+=c;
    return;
  }
  int mid=(L+R)>>1;
  if(x<=mid)update(t<<1,L,mid,x,c);
  else update(t<<1|1,mid+1,R,x,c);
  push_up(t);
}

inline int query(int t,int L,int R,int l,int r){
  if(l<=L&&R<=r) return tree[t];
  int mid=(L+R)>>1,ans=0;
  if(l<=mid)ans+=query(t<<1,L,mid,l,r);
  if(r>mid)ans+=query(t<<1|1,mid+1,R,l,r);
  return ans;
}

int main(){
  int n,m,op,x,c,r,l;
  while(~scanf("%d%d",&n,&m)){
    build(1,1,n);
    while(m--){
      scanf("%d",&op);
      if(op){
        scanf("%d%d",&x,&c);
        update(1,1,n,x,c);
      }else{
        scanf("%d%d",&l,&r);
        printf("%d\n",query(1,1,n,l,r));
      }
    }
  }
}
