/*************************************************************************
       File Name: A.cpp
       ID: obsoles1
       PROG: 
       LANG: C++ 
       Mail: 384099319@qq.com 
       Created Time: 日  4/17 15:37:56 2016
************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
//using namespace std;
const int N=100010;
int tree[N<<2];

template<class T>
inline bool read(T &n){
  T x = 0, tmp = 1;
  char c = getchar();
  while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
  if(c == EOF) return false;
  if(c == '-') c = getchar(), tmp = -1;
  while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
  n = x*tmp;
  return true;
}
template <class T>
inline void write(T n){
  if(n < 0){
    putchar('-');
    n = -n;
  }
  int len = 0,data[20];
  while(n){
    data[len++] = n%10;
    n /= 10;
  }
  if(!len) data[len++] = 0;
  while(len--) putchar(data[len]+48);
}

void push_up(int t){
  tree[t]=Max(tree[t<<1],tree[t<<1|1]);
}

void update(int t,int L,int R,int x,int v){
  if(L==R){tree[t]+=v;return;}
  int mid=(R+L)>>1;
  if(x<=mid)update(t<<1,L,mid,x,v);
  else update(t<<1|1,mid+1,R,x,v);
  push_up(t);
}

int query(int t,int L,int R,int l,int r){
  if(l<=L && R<=r)return tree[t];
  int mid=(L+R)>>1;
  int ans=0;
  if(l<=mid)ans=Max(ans,query(t<<1,L,mid,l,r));
  if(r>mid)ans=Max(ans,query(t<<1|1,mid+1,R,l,r));
  return ans;
}

int main(){
  int n,q,t,p,x,ans;
  //while(~scanf("%d%d",&n,&q)){
  while(read(n) && read(q)){
    Mem0(tree);
    while(q--){
      //scanf("%d%d%d",&t,&p,&x);
      read(t),read(p),read(x);
      if(t==1)update(1,1,n,p,x);
      else if(t==2){
        ans=query(1,1,n,p,x);
        write(ans);
        putchar('\n');
        //printf("%d\n",query(1,1,n,p,x));
      }
    }
  }
}
