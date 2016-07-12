/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日  3/ 6 13:03:20 2016
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
struct node{
  int lazy,maxn;
}tr[N<<2];
int x[N];

void push_up(int t){
  tr[t].maxn=Max(tr[t<<1].maxn,tr[t<<1|1].maxn);
}

void push_down(int t){
  if(!tr[t].lazy)return;
  tr[t<<1].maxn+=tr[t].lazy;
  tr[t<<1|1].maxn+=tr[t].lazy;
  tr[t<<1].lazy+=tr[t].lazy;
  tr[t<<1|1].lazy+=tr[t].lazy;
  tr[t].lazy=0;
}

void update(int t,int L,int R,int l,int r){
  if(l<=L && R<=r){
    tr[t].maxn++;
    tr[t].lazy++;
    return;
  }
  push_down(t);
  int mid=(L+R)>>1;
  if(l<=mid)update(t<<1,L,mid,l,r);
  if(r>mid)update(t<<1|1,mid+1,R,l,r);
  push_up(t);
}

int main(){
  int n,k,i,t,m;
  while(~scanf("%d%d",&n,&k)){
    Mem0(tr);
    m=0;
    for(i=1;i<=n;++i){
      scanf("%d",x+i);
      m=Max(m,x[i]+1);
    }
    for(i=1;i<=n;++i){
      update(1,1,m,x[i]+1,x[i]+1000);
    }
    //cout<<"tr[1].maxn="<<tr[1].maxn<<endl;
    //cout<<"k="<<k<<endl;
    int ans=ceil((double)tr[1].maxn/k);
    printf("%d\n",ans);
  }
}
