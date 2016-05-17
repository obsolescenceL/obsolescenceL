/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  4/18 18:06:48 2016
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
int t[N],l[N],r[N],p[N<<1],m;//ans;
struct node{
  int sum,len,x;
  bool add,tmp;
}tree[N<<2];

int get_id(int x){
  return lower_bound(p+1,p+m+1,x)-p;
}

void push_up(int t){
  //if(t==11)cout<<"46===tree["<<t<<"].sum="<<tree[t].sum<<endl;
  tree[t].sum=tree[t<<1].sum+tree[t<<1|1].sum;
  tree[t].sum+=tree[t].x*tree[t].tmp;
  tree[t].sum=Min(tree[t].len,tree[t].sum);
  //cout<<"tree["<<t<<"].sum="<<tree[t].sum<<endl;
  tree[t].x=tree[t].len-tree[t<<1].len-tree[t<<1|1].len;
  //cout<<"push_up!---tree["<<t<<"].sum="<<tree[t].sum<<endl;
  //cout<<"tree["<<t<<"].x="<<tree[t].x<<endl;
}

void push_down(int t){
  //if(t==11)cout<<"58===tree["<<t<<"].sum="<<tree[t].sum<<endl;
  if(!tree[t].add)return;
  //cout<<"t="<<t<<endl;
  tree[t].tmp=tree[t<<1].tmp=tree[t<<1|1].tmp=1;
  tree[t<<1].sum=tree[t<<1].len;
  tree[t<<1|1].sum=tree[t<<1|1].len;
  tree[t<<1].add=tree[t<<1|1].add=1;
  tree[t].add=0;
  //cout<<"tree["<<t<<"].tmp="<<tree[t].tmp<<endl;
}

void build(int t,int L,int R){
  //if(t==11)cout<<"69===tree["<<t<<"].sum="<<tree[t].sum<<endl;
  tree[t].len=p[R]-p[L]+1;
  //tree[t].sum=0;
  //cout<<"L="<<L<<" R="<<R<<endl;
  //cout<<"p["<<L<<"]="<<p[L]<<" p["<<R<<"]="<<p[R]<<endl;
  //cout<<"tree["<<t<<"]="<<tree[t].len<<endl;
  if(L==R)return;
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
  push_up(t);
}

void update(int t,int L,int R,int l,int r){
  //if(t==11)cout<<"83===tree["<<t<<"].sum="<<tree[t].sum<<endl;
  //cout<<"L="<<L<<" R="<<R<<endl;
  if(tree[t].sum==tree[t].len)return;
  if(l<=L && R<=r){
    tree[t].sum=tree[t].len;
    //cout<<"tree["<<t<<"].sum="<<tree[t].sum<<endl;
    tree[t].add=1;
    return;
  }
  push_down(t);
  int mid=(L+R)>>1,f=0;
  if(l<=mid)f++,update(t<<1,L,mid,l,r);
  if(r>mid)f++,update(t<<1|1,mid+1,R,l,r);
  if(f==2)tree[t].tmp=1;
  //cout<<"tree["<<t<<"].tmp="<<tree[t].tmp<<endl;
  push_up(t);
}

int query(int t,int L,int R,int l,int r){
  //if(t==11)cout<<"102===tree["<<t<<"].sum="<<tree[t].sum<<endl;
  //cout<<"l="<<l<<" r="<<r<<endl;
  //cout<<"L="<<L<<" R="<<R<<endl;
  if(l<=L && R<=r){
    //cout<<"tree["<<t<<"].sum="<<tree[t].sum<<endl;
    //cout<<"tree["<<t<<"].len="<<tree[t].len<<endl;
    return tree[t].sum;
  }
  push_down(t);
  int mid=(L+R)>>1,f=0,ans=0;
  if(l<=mid)f++,ans+=query(t<<1,L,mid,l,r);
  //cout<<"ans="<<ans<<endl;
  if(r>mid)f++,ans+=query(t<<1|1,mid+1,R,l,r);
  //cout<<"ans="<<ans<<endl;
  //push_up(t);
  //cout<<"tree["<<t<<"].len="<<tree[t].len<<endl;
  if(f==2)ans=Min(tree[t].len,ans+tree[t].tmp*tree[t].x);
  //cout<<"ans="<<ans<<endl;
  return ans;
}

int main(){
  //freopen("wa.txt","w",stdout);
  int n,q,i;
  while(~scanf("%d%d",&n,&q)){
    Mem0(tree);
    for(i=1;i<=q;++i){
      scanf("%d%d%d",&t[i],&l[i],&r[i]);
      p[i*2-1]=l[i];
      p[i<<1]=r[i];
    }
    sort(p+1,p+q*2+1);
    m=unique(p+1,p+q*2+1)-(p+1);
    build(1,1,m);
    //cout<<"m="<<m<<endl;
    for(i=1;i<=q;++i){
      if(t[i]==1){
        //cout<<"get_id(l["<<i<<"])="<<get_id(l[i])<<endl;
        //cout<<"get_id(r["<<i<<"])="<<get_id(r[i])<<endl;
        update(1,1,m,get_id(l[i]),get_id(r[i]));
        //cout<<"--------"<<endl;
      }else{
        //cout<<"l["<<i<<"]="<<l[i]<<" r["<<i<<"]="<<r[i]<<endl;
        //cout<<"l="<<get_id(l[i])<<" r="<<get_id(r[i])<<endl;
        //ans=0;
        int ans=query(1,1,m,get_id(l[i]),get_id(r[i]));
        printf("%d\n",r[i]-l[i]+1-ans);
        //cout<<"ans="<<ans<<endl;
      }
      //cout<<"--------"<<endl;
    }
  }
}
