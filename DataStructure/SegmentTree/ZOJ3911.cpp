/*************************************************************************
     File Name: I.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日 10/11 12:21:15 2015
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
const int N=100010,M=1e7+10;
struct node{
  int num,cnt,rep;
}tree[N<<2];
int p[M/3],k;
bool flag[M];

void push_up(int t){
  tree[t].cnt=tree[t<<1].cnt+tree[t<<1|1].cnt;
}

void push_down(int t,int L,int R){
  //cout<<"tree["<<t<<"].rep="<<tree[t].rep<<endl;
  if(tree[t].rep==-1)return;
  //cout<<"L="<<L<<" R="<<R<<endl;
  int mid=(L+R)>>1;
  if(tree[t].cnt){
    tree[t<<1].cnt=mid-L+1;
    tree[t<<1|1].cnt=R-mid;
  }else tree[t<<1].cnt=tree[t<<1|1].cnt=0;
  tree[t<<1].num=tree[t<<1|1].num=tree[t<<1].rep=tree[t<<1|1].rep=tree[t].rep;
  tree[t].rep=-1;
}

void build(int t,int L,int R){
  tree[t].rep=-1;
  if(L==R){
    scanf("%d",&tree[t].num);
    //cout<<"tree["<<t<<"]="<<tree[t].num<<endl;
    if(!flag[tree[t].num])
      tree[t].cnt=1;
    else tree[t].cnt=0;
    //cout<<"tree["<<t<<"]="<<tree[t].cnt<<endl;
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid),build(t<<1|1,mid+1,R);
  push_up(t);
}

void add(int t,int L,int R,int x,int v){
  if(L==R){
    tree[t].num+=v;
    //cout<<"tree["<<t<<"].num="<<tree[t].num<<endl;
    if(!flag[tree[t].num])
      tree[t].cnt=1;
    else tree[t].cnt=0;
    //cout<<"tree["<<t<<"].cnt="<<tree[t].cnt<<endl;
    return;
  }
  push_down(t,L,R);
  int mid=(L+R)>>1;
  if(x<=mid)add(t<<1,L,mid,x,v);
  if(x>mid)add(t<<1|1,mid+1,R,x,v);
  push_up(t);
}

void replace(int t,int L,int R,int l,int r,int v){
  //cout<<"L="<<L<<" R="<<R<<endl;
  //cout<<"l="<<l<<" r="<<r<<endl;
  if(l<=L && R<=r){
    tree[t].rep=v;
    //cout<<"tree["<<t<<"].rep="<<tree[t].rep<<endl;
    tree[t].num=v;
    if(!flag[v])tree[t].cnt=R-L+1;
    else tree[t].cnt=0;
    //cout<<"tree["<<t<<"].num="<<tree[t].num<<endl;
    //cout<<"tree["<<t<<"].cnt="<<tree[t].cnt<<endl;
    return;
  }
  push_down(t,L,R);
  int mid=(L+R)>>1;
  if(l<=mid)replace(t<<1,L,mid,l,r,v);
  if(r>mid)replace(t<<1|1,mid+1,R,l,r,v);
  push_up(t);
}

int query(int t,int L,int R,int l,int r){
  if(l<=L && R<=r)return tree[t].cnt;
  push_down(t,L,R);
  int mid=(L+R)>>1,ans=0;
  if(l<=mid)ans+=query(t<<1,L,mid,l,r);
  if(r>mid)ans+=query(t<<1|1,mid+1,R,l,r);
  return ans;
}

void init(){
  for(int i=2;i<M;++i){
    if(!flag[i])p[k++]=i;
    for(int j=0;i*p[j]<M;++j){
      flag[i*p[j]]=1;
      if(i%p[j]==0)break;
    }
  }
}

int main(){
  int t,n,m,l,r,x,v;
  char op[2];
  init();
  flag[0]=flag[1]=1;
  //cout<<"p["<<k-1<<"]="<<p[k-1]<<endl;
  //for(int i=0;i<=100;++i)
    //cout<<"flag["<<i<<"]="<<flag[i]<<endl;
    //cout<<"p["<<i<<"]="<<p[i]<<endl;
  while(~scanf("%d",&t)){
    //cout<<"t="<<t<<endl;
    while(t--){
      //cout<<"-----------------"<<endl;
      Mem0(tree);
      scanf("%d%d",&n,&m);
      //cout<<"n="<<n<<" m="<<m<<endl;
      build(1,1,n);
      while(m--){
        scanf("%s",op);
        //cout<<op<<' ';
        if(op[0]=='A'){
          scanf("%d%d",&v,&x);
          //cout<<v<<' '<<x<<endl;
          add(1,1,n,x,v);
          //cout<<"-----------"<<endl;
        }else if(op[0]=='R'){
          scanf("%d%d%d",&v,&l,&r);
          //cout<<v<<' '<<l<<' '<<r<<endl;
          replace(1,1,n,l,r,v);
          //cout<<"-----------"<<endl;
        }else{
          scanf("%d%d",&l,&r);
          //cout<<l<<' '<<r<<endl;
          printf("%d\n",query(1,1,n,l,r));
        }
      }
    }
  }
}
