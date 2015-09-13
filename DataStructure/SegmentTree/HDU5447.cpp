/*************************************************************************
     File Name: 1007.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年09月13日 星期日 09时03分15秒
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
const int N=1010;
int tree[N<<2],maxn;

inline void push_up(int t){
  tree[t]=Max(tree[t<<1],tree[t<<1|1]);
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

inline void query(int t,int L,int R,int l,int r){
  if(L>=l&&r>=R){
    maxn=Max(maxn,tree[t]);
    return;
  }
  int mid=(L+R)>>1;
  if(l<=mid)query(t<<1,L,mid,l,r);
  if(r>mid)query(t<<1|1,mid+1,R,l,r);
  //cout<<"maxn="<<maxn<<endl;
}

int main(){
  int t,n,q,l,r;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&n);
      build(1,1,n);
      scanf("%d",&q);
      while(q--){
        maxn=0;
        scanf("%d%d",&l,&r);
        query(1,1,n,l,r);
        printf("%d\n",maxn);
      }
    }
  }
}
