/*************************************************************************
     File Name: HYSBZ1500.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月14日 星期五 10时31分39秒
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
using namespace std;
const int N=1000010;
struct SplayTree{
  int root,sz;
  int ch[N][2],pre[N],size[N],v[N];
  int num[N],sum[N];
  bool f[N];

  void rotate(int x,int to){
    int y=pre[x],z=pre[y];
    pre[ch[x][to]]=y;
    push_down(y);
    ch[y][to^1]=ch[x][to];
    pre[ch[x][to]]=y;
    ch[z][ch[z][1]==y]=x;
    pre[x]=z;
    ch[x][to]=y;
    pre[y]=x;
    push_up(y);
  }

  void splay(int x,int goal){
    if(x!=goal){
      push_down(x);
      while(pre[x]!=goal){
        if(ch[pre[x]][0]==x)
          rotate(x,1);
        else rotate(x,0);
      }
      push_up(x);
      if(!goal)root=x;
    }
  }
  
  void NewNode(int &x,int fa,int val){
    x=++sz;
    ch[x][0]=ch[x][1]=0;
    pre[x]=fa,v[x]=val;
    size[x]=1,f[x]=0;
  }

  void build(int &x,int L,int R,int fa){
    if(L<=R){
      int mid=(L+R)>>1;
      NewNode(x,fa,num[mid]);
      build(ch[x][0],L,mid-1,x);
      build(ch[x][1],mid+1,R,x);
      push_up(x);
    }
  }
      
  void init(int n){
    sz=root=0;
    ch[0][0]=ch[0][1]=0;
    v[0]=pre[0]=size[0]=0;
    f[0]=0;
    NewNode(root,0,0);
    NewNode(ch[root][1],root,0);
    size[root]++;
    build(ch[ch[root][1]][0],0,n-1,ch[root][1]);
    push_up(ch[root][1]);
    push_up(root);
  }

  void push_up(int x){
    size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
  }
      
  void push_down(int x){
    if(f[x]){
      f[x]^=1;
      f[ch[x][0]]^=1;
      f[ch[x][1]]^=1;
      swap(ch[x][0],ch[x][1]);
    }
  }
      
  int q_min(int x){
    push_down(x);
    while(ch[x][0]){
      x=ch[x][0];
      push_down(x);
    }
    return x;
  }
      
  void insert(int x,int n){
    if(!n)return;
    x=find_kth(x);
    splay(x,0);
    int y=q_min(ch[x][1]);
    splay(y,x);
    build(ch[y][0],0,n-1,y);
    push_up(y);
    push_up(x);
  }

  int find_kth(int k){
    int x;
    push_down(root);
    for(x=root;size[ch[x][0]]+1!=k;){
      if(size[ch[x][0]]+1>k)x=ch[x][0];
      else{
        k-=size[ch[x][0]]+1;
        x=ch[x][1];
      }
      push_down(x);
    }
    return x;
  }

  void del(int x,int y){
    x=find_kth(x);
    y=find_kth(y+1);
    splay(x,0);
    splay(y,x);
    ch[y][0]=0;
    push_up(y);
    push_up(x);
  }

  void flip(int x,int y){
    x=find_kth(x);
    y=find_kth(y);
    splay(x,0);
    splay(y,x);
    f[ch[y][0]]^=1;
  }

  void prin
}tree;
      
int main(){
  int n,m,i;
  char op[20];
  while(~scanf("%d%d",&n,&m)){
    for(i=0;i<n;++i)scanf("%d",&tree.num[i]);
    while(m--){
      scanf("%s",op);
      if(op[0]=='I'){

      }else if(op[0]=='D'){
      
      }else if(op[0]=='R'){

      }else if(op[0]=='G'){

      }else if(op[2]=='K'){

      }else{

      }
    }
  }
}
