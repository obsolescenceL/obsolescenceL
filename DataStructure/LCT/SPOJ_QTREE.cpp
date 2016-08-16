/*************************************************************************
     File Name: SPOJ_QTREE.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月18日 星期二 21时04分52秒
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
const int N=10010,M=20010,INF=0x3f3f3f3f;
int first[N],next[M],v[M],cos[M],e;
bool vis[N];
struct LCT{
  int ch[N][2],pre[N],val[N],belong[N],bef[N],key[N];

  void init(){
    Mem0(ch);
    Mem0(pre);
    val[0]=key[0]=-INF;
  }

  void push_up(int x){
    val[x]=Max(key[x],Max(val[ch[x][0]],val[ch[x][1]]));
  }

  void rotate(int x,int to){
    int y=pre[x],z=pre[y];
    ch[y][to^1]=ch[x][to];
    pre[ch[x][to]]=y;
    ch[z][ch[z][1]==y]=x;
    pre[x]=z;
    ch[x][to]=y;
    pre[y]=x;
    push_up(y);
  }

  void splay(int x){
    int t;
    for(t=x;pre[t];t=pre[t]);
    if(t!=x){
      bef[x]=bef[t];
      bef[t]=0;
      while(pre[x]){
        if(ch[pre[x]][0]==x)
          rotate(x,1);
        else rotate(x,0);
      }
      push_up(x);
    }
  }

  void access(int x){
    int fa;
    for(fa=0;x;x=bef[x]){
      splay(x);
      bef[ch[x][1]]=x;
      pre[ch[x][1]]=0;
      ch[x][1]=fa;
      pre[fa]=x;
      fa=x;
      push_up(x);
    }
  }

  int query(int x,int y){
    access(y);
    for(y=0;x;x=bef[x]){
      splay(x);
      if(!bef[x])return Max(val[y],val[ch[x][1]]);
      bef[ch[x][1]]=x;
      bef[y]=0;
      pre[ch[x][1]]=0;
      ch[x][1]=y;
      pre[y]=x;
      y=x;
      push_up(x);
    }
    return 0;
  }

  void change(int x,int y){
    int t=belong[x-1];
    key[t]=y;
    splay(t);
  }
}lct;

void Addedge(int x,int y,int val){
  v[e]=y;
  cos[e]=v;
  next[e]=first[x];
  first[x]=e++;
}

void bfs(int x){
  int i,y;
  queue<int> q;
  Mem0(vis);
  q.push(x);
  vis[x]=1;
  while(!q.empty()){
    x=q.front(),q.pop();
    for(i=first[x];i!=-1;i=next[i]){
      y=v[i];
      if(!vis[y]){
        lct.bef[y]=x;
        lct.key[y]=lct.val[y]=cos[i];
        lct.belong[i>>1]=y;
        vis[y]=1;
        q.push(y);
      }
    }
  }
}

int main(){



