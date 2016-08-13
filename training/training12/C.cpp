/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月01日 星期六 13时54分44秒
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
const int N=100010,mod=1e9+7;
ll f[N],v[N],cnt_l[N];





int main(){
  int n,q,a,b,l,r;
  while(~scanf("%d%d",&n,&q)){
    Mem0(cnt_l),Mem0(cnt_r);
    scanf("%d%d",&f[1],&f[2]);
    scanf("%d%d",&a,&b);
    for(i=3;i<=n;++i)
      f[i]=((a*f[i-2]%mod)+(b*f[i-1]%mod))%mod;
    for(i=1;i<=n;++i)
      scanf("%I64d",v+i);
    while(q--){
      scanf("%d%d",&l,&r);
      cnt_l[l]++;
    }
    for(i=1;i<=n;++i){
      if(cnt_l[i])v[i]+=cnt_l[i]*f













/*
struct Tree{
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
  if(L==R){
    scanf("%I64d",&tree[t].sum);
    tree[t].add=0;
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
  push_up(t);
}

void update(int t,int L,int R,int l,int r,ll c){
  if(l<=L&&R<=r){
    tree[t].sum+=(ll)(R-L+1)*c;


int main(){
  int n,q,a,b,l,r;
  while(~scanf("%d%d",&n,&q)){
    scanf("%d%d",&f[1],&f[2]);
    scanf("%d%d",&a,&b);
    build(1,1,n);
    while(q--){
      scanf("%d%d",&l,&r);
      update
*/
