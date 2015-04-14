/*************************************************************************
     File Name: HDU1698.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月14日 星期二 18时46分23秒
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
using namespace std;
const int N=200001;
int maxn;
struct node{
  int maxn;
  bool flag;
}tree[N<<2];

inline void push_up(int t){
  tree[t].maxn=Max(tree[t<<1].maxn,tree[t<<1|1].maxn);
}

//inline void push_down(int t,int L,int R){

inline void build(int t,int L,int R){
  if(L==R){
    scanf("%d",&tree[t].maxn);
    //cout<<"tree["<<t<<"].maxn="<<tree[t].maxn<<endl;
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
  push_up(t);
}

inline void update(int t,int L,int R,int id,int c){
  if(L==id&&R==id){
    tree[t].maxn=c;
    //cout<<"tree["<<t<<"].maxn="<<tree[t].maxn<<endl;
    return;
  }
  int mid=(R+L)>>1;
  if(id<=mid)update(t<<1,L,mid,id,c);
  else update(t<<1|1,mid+1,R,id,c);
  //cout<<L<<' '<<R<<endl;
  push_up(t);
}

inline void query(int t,int L,int R,int l,int r){
  if(L>=l&&r>=R){
    maxn=Max(maxn,tree[t].maxn);
    return;
  }
  int mid=(L+R)>>1;
  if(l<=mid)query(t<<1,L,mid,l,r);
  if(r>mid)query(t<<1|1,mid+1,R,l,r);
  //cout<<"maxn="<<maxn<<endl;
}

int main(){
  int n,m,l,r,id,c;
  char op[5];
  while(~scanf("%d%d",&n,&m)){
    build(1,1,n);
    while(m--){
      scanf("%s",op);
      if(op[0]=='Q'){
        scanf("%d%d",&l,&r);
        maxn=0;
        query(1,1,n,l,r);
        printf("%d\n",maxn);
      }else{
        scanf("%d%d",&id,&c);
        update(1,1,n,id,c);
      }
    }
  }
}
