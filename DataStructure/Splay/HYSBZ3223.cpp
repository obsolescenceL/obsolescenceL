/*************************************************************************
     File Name: HYSBZ3223.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月12日 星期三 15时11分17秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1000010;
struct SplayTree{
  int root,siz;
  int ch[N][2],pre[N],v[N],size[N];
  bool f[N];

  void init(int n){
    siz=root=0;
    ch[0][0]=ch[0][1]=0;
    v[0]=pre[0]=size[0]=0;
    f[0]=0;
    NewNode(root,0,-1);
    NewNode(ch[root][1],root,-1);
    size[root]++;
    build(ch[ch[root][1]][0],1,n,ch[root][1]);
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

  void NewNode(int &x,int fa,int val){
    x=++siz;
    //cout<<"siz="<<siz<<' ';
    ch[x][0]=ch[x][1]=0;
    //cout<<"ch["<<x<<"]=0"<<' ';
    pre[x]=fa;
    //cout<<"pre["<<x<<"]="<<fa<<' ';
    v[x]=val;
    //cout<<"v["<<x<<"]="<<val<<endl;
    size[x]=1;
    f[x]=0;
  }

  void build(int &x,int L,int R,int fa){
    if(L<=R){
      int mid=(L+R)>>1;
      NewNode(x,fa,mid);
      build(ch[x][0],L,mid-1,x);
      build(ch[x][1],mid+1,R,x);
      push_up(x);
    }
  }

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

  int find_kth(int k){
    int x;
    push_down(root);
    for(x=root;size[ch[x][0]]+1 != k;){
      if(size[ch[x][0]]+1 > k)
        x=ch[x][0];
      else{
        k-=size[ch[x][0]]+1;
        x=ch[x][1];
      }
      push_down(x);
    }
    return x;
  }

  void flip(int x,int y){
    //cout<<"--------------"<<endl;
    x=find_kth(x);
    y=find_kth(y+2);
    //cout<<"x="<<x<<" y="<<y<<endl;
    splay(x,0);
    splay(y,x);
    //y=ch[y][0];
    f[ch[y][0]]^=1;
  }

  void print(int x){
    if(x){
      push_down(x);
      print(ch[x][0]);
      if(v[x]>0)printf("%d ",v[x]);
      print(ch[x][1]);
    }
  }
}tree;

int main(){
  int n,m,i,l,r;
  while(~scanf("%d%d",&n,&m)){
    //cout<<"n="<<n<<" m="<<m<<endl;
    tree.init(n);
    while(m--){
      scanf("%d%d",&l,&r);
      //cout<<"l="<<l<<" r="<<r<<endl;
      tree.flip(l,r);
      //cout<<"--------------"<<endl;
    }
    tree.print(tree.root);
  }
}
