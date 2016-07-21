/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月09日 星期六 13时23分18秒
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
const int N=32768+10;
struct node{
  int id,p;
}tree[N<<2];
int k,p[N],ans[N],cnt;

void push_up(int t){
  int maxt,mint,tmp;
  if(tree[t<<1].p>=tree[t<<1|1].p)
    maxt=t<<1,mint=t<<1|1;
  else maxt=t<<1|1,mint=t<<1;
  tmp=tree[maxt].p-tree[mint].p;
  tree[t].p=Min(p[tree[maxt].id],tmp+k);
  tree[t].id=tree[maxt].id;
}

void build(int t,int L,int R){
  if(L==R){
    tree[t].p=p[L];
    //cout<<"tree["<<t<<"].p="<<tree[t].p<<endl;
    //scanf("%d",&tree[t].p);
    tree[t].id=L;
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid),build(t<<1|1,mid+1,R);
  push_up(t);
}

void query(int t,int L,int R,int x){
  if(L==R)return;
  int mid=(L+R)>>1;
  if(x<=mid){
    ans[cnt--]=tree[t<<1|1].id;
    //cout<<"t<<1|1="<<(t<<1|1)<<endl;
    query(t<<1,L,mid,x);
  }else{
    ans[cnt--]=tree[t<<1].id;
    //cout<<"t<<1="<<(t<<1)<<endl;
    query(t<<1|1,mid+1,R,x);
  }
}

int main(){
  int t,n,nn,i;
  while(~scanf("%d",&t)){
    while(t--){
      Mem0(tree);
      scanf("%d%d",&n,&k);
      cnt=nn=n;
      //cout<<"n="<<n<<" k="<<k<<endl;
      n=(int)pow(2.0,n);
      //cout<<"n="<<n<<endl;
      for(i=1;i<=n;++i){
        scanf("%d",p+i);
        //cout<<"p["<<i<<"]="<<p[i]<<endl;
      }
      build(1,1,n);
      query(1,1,n,tree[1].id);
      printf("%d\n",tree[1].id);
      for(i=1;i<nn;++i)
        printf("%d ",ans[i]);
      printf("%d\n",ans[nn]);
    }
  }
}
