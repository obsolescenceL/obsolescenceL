/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月13日 星期三 18时04分37秒
 ************************************************************************/
//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#define left t<<1
#define right t<<1|1
using namespace std;
const int N=1e5+10;
struct node{
  int max1,max2;
}tree[N<<2];
int max1,max2;

void push_up(int t){
  if(tree[left].max1>tree[right].max1){
    tree[t].max1=tree[left].max1;
    tree[t].max2=Max(tree[left].max2,tree[right].max1);
  }else{
    tree[t].max1=tree[right].max1;
    tree[t].max2=Max(tree[right].max2,tree[left].max1);
  }
  //cout<<"tree["<<t<<"]="<<tree[t].max1<<" , "<<tree[t].max2<<endl;
}

void build(int t,int L,int R){
  if(L==R){
    scanf("%d",&tree[t].max1);
    tree[t].max2=0;
    return;
  }
  int mid=(L+R)>>1;
  build(left,L,mid);
  build(right,mid+1,R);
  push_up(t);
}

void update(int t,int L,int R,int x,int v){
  if(L==R){
    tree[t].max1=v;
    return;
  }
  int mid=(L+R)>>1;
  if(x<=mid)update(left,L,mid,x,v);
  else update(right,mid+1,R,x,v);
  push_up(t);
}

void query(int t,int L,int R,int l,int r){
  if(l<=L && R<=r){
    if(tree[t].max1>max1){
      max2=Max(max2,max1);
      max1=tree[t].max1;
      max2=Max(max2,tree[t].max2);
    }else{
      max2=Max(max2,tree[t].max1);
    }
    return;
  }
  int mid=(L+R)>>1;
  if(l<=mid)query(left,L,mid,l,r);
  if(r>mid)query(right,mid+1,R,l,r);
}

int main(){
  int n,m,l,r;
  char op[2];
  while(~scanf("%d",&n)){
    Mem0(tree);
    build(1,1,n);
    scanf("%d",&m);
    while(m--){
      scanf("%s%d%d",op,&l,&r);
      if(op[0]=='U')update(1,1,n,l,r);
      else{
        max1=max2=0;
        query(1,1,n,l,r);
        //cout<<"max1="<<max1<<" max2="<<max2<<endl;
        printf("%d\n",max1+max2);
      }
    }
  }
}
