/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  4/25 21:36:49 2016
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
#define lowbit(x) (x&(-x))
using namespace std;
const int N=200010;
struct node{
  ll a,b;
  int ord;
}c[N];
ll a[N],s[N];
int n;

bool cmp1(node lhs,node rhs){
  return lhs.a<rhs.a || (lhs.a==rhs.a && lhs.b<rhs.b);
}

bool cmp2(node lhs,node rhs){
  return lhs.b<rhs.b;
}

void update(int x,ll v){
  for(;x<=n;x+=lowbit(x))s[x]+=v;
}

ll get_sum(int x){
  ll tmp=0;
  for(;x>0;x-=lowbit(x))tmp+=s[x];
  return tmp;
}

int main(){
  int i,j;
  ll k,b,u,v;
  ios::sync_with_stdio(0);
  cin>>n>>u>>v;
  for(i=1;i<=n;++i){
    cin>>k>>b;
    c[i].a=k*(u-1)+b;
    c[i].b=k*(v+1)+b;
  }
  sort(c+1,c+1+n,cmp1);
  for(i=1;i<=n;++i)
    //cout<<"c["<<i<<"]=("<<c[i].a<<','<<c[i].b<<endl;
  for(i=1;i<=n;++i)c[i].ord=i;
  sort(c+1,c+1+n,cmp2);
  a[c[1].ord]=1;
  for(i=2,j=1;i<=n;++i){
    if(c[i].b!=c[i-1].b)j++;
    a[c[i].ord]=j;
  }
  //for(i=1;i<=n;++i)
    //cout<<"c["<<i<<"]=("<<c[i].a<<','<<c[i].b<<endl;
  //for(i=1;i<=n;++i)a[c[i].ord]=i;
  ll ans=0;
  for(i=1;i<=n;++i)
    update(a[i],1),ans+=i-get_sum(a[i]);
  cout<<ans<<endl;
}
