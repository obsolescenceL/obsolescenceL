/*************************************************************************
     File Name: HYSBZ1269.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月13日 星期四 14时06分43秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
#include<algorithm>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
const int N=2*1024*1024+10;
using namespace std;
struct SplayTree{
  int root,sz;
  int ch[N][2],pre[N],size[N];
  char v[N],s[N];
  bool f[N];

  void init(){
    sz=root=0;
    ch[0][0]=ch[0][1]=0;
    v[0]=pre[0]=size[0]=0;
    f[0]=0;
    NewNode(root,0,0);
    NewNode(ch[root][1],root,0);
    size[root]++;
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

  void NewNode(int &x,int fa,char val){
    x=++sz;
    ch[x][0]=ch[x][1]=0;
    pre[x]=fa,v[x]=val;
    size[x]=1,f[x]=0;
    //cout<<"sz="<<sz<<' '<<"ch["<<x<<"]=0"<<' '<<"pre["<<x<<"]="<<fa<<' '<<"v["<<x<<"]="<<val<<endl;
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

  void build(int &x,int L,int R,int fa){
    if(L<=R){
      int mid=(L+R)>>1;
      NewNode(x,fa,s[mid]);
      build(ch[x][0],L,mid-1,x);
      build(ch[x][1],mid+1,R,x);
      push_up(x);
    }
  }

  void insert(int x,int n){
    if(!n)return;
    x=find_kth(x);
    splay(x,0);
    int y=q_min(ch[x][1]);
    splay(y,x);
    build(ch[y][0],0,n-1,y);
    //cout<<"s="<<s<<endl;
    push_up(y);
    push_up(x);
  }

  int find_kth(int k){
    int x;
    push_down(root);
    for(x=root;size[ch[x][0]]+1 != k;){
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
    //cout<<"x="<<x<<" y="<<y<<endl;
    splay(x,0);
    splay(y,x);
    ch[y][0]=0;
    push_up(y);
    push_up(x);
  }

  void flip(int x,int y){
    x=find_kth(x);
    y=find_kth(y+1);
    //cout<<"x="<<x<<" y="<<y<<endl;
    splay(x,0);
    splay(y,x);
    f[ch[y][0]]^=1;
  }

  void print(int x){
    x=find_kth(x+1);
    //cout<<"x="<<x<<endl;
    //splay(x,0);
    printf("%c\n",v[x]);
  }

   void print_1(int x){
    if(x){
      push_down(x);
      print_1(ch[x][0]);
      //cout<<"v["<<x<<"]="<<v[x]<<endl;
      //if(v[x]>0)printf("%c",v[x]);
      print_1(ch[x][1]);
    }
  }
}tree;


int main(){
  int n,x,cur;char op[20];
  while(~scanf("%d",&n)){
    //cout<<"n="<<n<<endl;
    tree.init();
    cur=0;
    while(n--){
      scanf("%s",op);
      //cout<<"op="<<op<<' ';
      //cout<<"cur="<<cur<<endl;
      //cout<<"v[root]="<<tree.v[tree.root+2]<<endl;
      if(op[0]=='M'){
        scanf("%d",&x);
        //cout<<"x="<<x<<endl;
        cur=Min(tree.size[tree.root]-2,x);
      }else if(op[0]=='I'){
        scanf("%d",&x);
        //cout<<"x="<<x<<endl;
        getchar();
        //gets(tree.s);
        scanf("%[^\n]",tree.s);
        tree.insert(cur+1,x);
      }else if(op[0]=='D'){
        scanf("%d",&x);
        //cout<<"x="<<x<<endl;
        tree.del(cur+1,cur+x+1);
      }else if(op[0]=='R'){
        scanf("%d",&x);
        //cout<<"x="<<x<<endl;
        tree.flip(cur+1,cur+x+1);
      }else if(op[0]=='G'){
        //tree.print_1(tree.root);
        tree.print(cur+1);
      }else if(op[0]=='P'){
        cur=Max(0,cur-1);
      }else{
        cur=Min(tree.size[tree.root]-2,cur+1);
      }
      //tree.print_1(tree.root);
      //puts("");
    }
  }
}
