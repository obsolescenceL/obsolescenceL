/*************************************************************************
     File Name: 1008.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年09月26日 星期六 12时08分06秒
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
const int N=100010;
struct node{
  int op;
  ll y;
}a[N];
ll tree[N<<2];
int m;

void push_up(int t){
  tree[t]=(tree[t<<1]*tree[t<<1|1])%m;
}

void build(int t,int L,int R){
  if(L==R){
    if(a[L].op==1) tree[t]=a[L].y;
    else tree[t]=1;
    //cout<<"a["<<L<<"]="<<a[L].y<<endl;
    //cout<<"tree["<<t<<"]="<<tree[t]<<endl;
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid),build(t<<1|1,mid+1,R);
  push_up(t);
}

void update(int t,int L,int R,int x){
  if(L==R){
    tree[t]=1;
    return;
  }
  int mid=(R+L)>>1;
  if(x<=mid)update(t<<1,L,mid,x);
  else update(t<<1|1,mid+1,R,x);
  push_up(t);
}

int query(int t,int L,int R,int l,int r){
  if(L>=l&&R<=r){
    //cout<<"tree["<<t<<"]="<<tree[t]<<endl;
    return tree[t];
  }
  int mid=(R+L)>>1;
  ll ans=1;
  if(l<=mid)ans*=query(t<<1,L,mid,l,r);
  if(r>mid)ans*=query(t<<1|1,mid+1,R,l,r);
  ans%=m;
  return ans;
}

int main(){
  ios::sync_with_stdio(0);
  int t,n,op,i;
  while(cin>>t){
    for(int nc=1;nc<=t;++nc){
      cout<<"Case #"<<nc<<":\n";
      ll x=1,y;
      cin>>n>>m;
      for(i=1;i<=n;++i)
        cin>>a[i].op>>a[i].y;
      build(1,1,n);
      for(i=1;i<=n;++i){
        if(a[i].op==2)
          update(1,1,n,a[i].y);
        cout<<query(1,1,n,1,i)<<endl;;
        //cout<<"----------------"<<endl;
      }
    }
  }
}
