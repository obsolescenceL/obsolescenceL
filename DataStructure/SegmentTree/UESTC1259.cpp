/*************************************************************************
     File Name: Q.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 四  4/28 17:48:59 2016
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
#define left (t<<1)
#define right (t<<1|1)
using namespace std;
const int N=1e5+10;
struct node{
  ll b[2];
  int add;
}tree[N<<2];
ll b[2];

/*
void Print(ll x){
  //cout<<"x="<<x<<endl;
  int cnt=0;
  ll xx=x;
  for(;xx;xx>>=1)cnt++;
  while(cnt--){
    bool ans=x&(1ll<<cnt);
    printf("%d",ans);
  }
  puts("");
}
*/

void push_up(int t){
  for(int i=0;i<2;++i)
    tree[t].b[i]=tree[left].b[i] | tree[right].b[i];
}

void push_down(int t){
  if(tree[t].add==-1)return;
  for(int i=0;i<2;++i){
    tree[left].b[i]=tree[right].b[i]=0;
    if(tree[t].add/50==i){
      tree[left].b[i]|=1ll<<(tree[t].add%50);
      tree[right].b[i]|=1ll<<(tree[t].add%50);
    }
  }
  tree[left].add=tree[right].add=tree[t].add;
  tree[t].add=-1;
}

void build(int t,int L,int R){
  tree[t].add=-1;
  if(L==R){
    int x;
    tree[t].b[0]=tree[t].b[1]=0;
    scanf("%d",&x);
    x--;
    tree[t].b[x/50]|=1ll<<(x%50);
    //cout<<"x%50="<<x%50<<endl;
    //Print(tree[t].b[x/50]);
    return;
  }
  int mid=(L+R)>>1;
  build(left,L,mid);
  build(right,mid+1,R);
  push_up(t);
}

void update(int t,int L,int R,int l,int r,int v){
  if(l<=L && R<=r){
    tree[t].b[0]=tree[t].b[1]=0;
    tree[t].b[v/50]|=1ll<<(v%50);
    tree[t].add=v;
    return;
  }
  push_down(t);
  int mid=(L+R)>>1;
  if(l<=mid)update(left,L,mid,l,r,v);
  if(r>mid)update(right,mid+1,R,l,r,v);
  push_up(t);
}

void query(int t,int L,int R,int l,int r){
  if(l<=L && R<=r){
    for(int i=0;i<2;++i)
      b[i]|=tree[t].b[i];
    return;
  }
  push_down(t);
  int mid=(L+R)>>1;
  if(l<=mid)query(left,L,mid,l,r);
  if(r>mid)query(right,mid+1,R,l,r);
}

int main(){
  int n,m,i,ans,q,l,r,v;
  char op[2];
  bool tmp;
  scanf("%d%d",&n,&m);
  build(1,1,n);
  scanf("%d",&q);
  while(q--){
    scanf("%s%d%d",op,&l,&r);
    if(op[0]=='M'){
      scanf("%d",&v);
      //cout<<"v="<<v<<endl;
      update(1,1,n,l,r,--v);
    }else{
      b[0]=b[1]=ans=0;
      query(1,1,n,l,r);
      //Print(b[0]);
      //Print(b[1]);
      for(i=0;i<Min(m,50);++i){
        tmp=b[0]&(1ll<<i);
        ans+=tmp;
        //if(tmp)cout<<"i="<<i<<" ans="<<ans<<endl;
      }
      for(i=0;i<Max(0,m-50);++i){
        tmp=b[1]&(1ll<<i);
        ans+=tmp;
      }
      printf("%d\n",ans);
    }
  }
}

