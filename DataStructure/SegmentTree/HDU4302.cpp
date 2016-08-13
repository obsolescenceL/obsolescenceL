/*************************************************************************
     File Name: HDU4302.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月16日 星期四 10时10分15秒
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
using namespace std;
const int N=200000,INF=0x3f3f3f3f;
int dis,minn;
int cake[N],tree[N<<2];

void push_up(int t){
  tree[t]=tree[t<<1]+tree[t<<1|1];
}

void build(int t,int L,int R){
  if(L==R){
    tree[t]=0;
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
  push_up(t);
}

void update(int t,int L,int R,int x,bool flag){
  if(L==x&&R==x){
    if(flag){
      tree[t]++;
      return;
    }else{
      tree[t]=0;
      return;
    }
  }
  int mid=(L+R)>>1;
  if(x<=mid)update(t<<1,L,mid,x,flag);
  else update(t<<1|1,mid+1,R,x,flag);
  push_up(t);
}

void query(int t,int L,int R){
  if(L==R){
    if(tree[t])
      minn=Min(minn,Abs(L,dis));
    return;
  }
  int mid=(L+R)>>1;
  query(t<<1,L,mid);
  query(t<<1|1,mid+1,R);
}

int main(){
  int t,L,n,op,x,ans;
  bool flag;
  while(~scanf("%d",&t)){
    for(int nc=1;nc<=t;++nc){
      memset(cake,0,sizeof cake);
      dis=ans=0;flag=1;
      scanf("%d%d",&L,&n);
      build(1,0,L);
      while(n--){
        scanf("%d",&op);
        if(op){
          if(!tree[1])continue;
          minn=INF;
          query(1,0,L);
          if(dis-minn<0){
            dis+=minn,flag=1;
            if(!--cake[dis])
              update(1,0,L,dis,0);
            ans+=minn;
            continue;
          }
          if(flag){
            if(cake[dis+minn])
              dis+=minn;
            else flag=0,dis-=minn;
          }else{
            if(cake[dis-minn])
              dis-=minn;
            else flag=1,dis+=minn;
          }
          if(!--cake[dis])
            update(1,0,L,dis,0);
          ans+=minn;
        }else{
          scanf("%d",&x);
          cake[x]++;
          update(1,0,L,x,1);
        }
      }
      printf("Case %d: %d\n",nc,ans);
    }
  }
}
