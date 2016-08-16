/*************************************************************************
     File Name: HDU3308.cpp
     ID: obsoles1
     PROG: 求最长连续递增序列
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月20日 星期一 15时46分18秒
 ************************************************************************/
#include<cstdio>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define lson t<<1
#define rson t<<1|1
using namespace std;
const int N=100001;
struct node{
  int cnt;//区间长度
  int ln,rn;//左边界，右边界
  int ls,rs,ms;//左连续，右连续，LCIS
}T[N<<2];

void push_up(int t){
  T[t].ls=T[lson].ls;
  T[t].rs=T[rson].rs;
  T[t].ln=T[lson].ln;
  T[t].rn=T[rson].rn;
  T[t].ms=Max(T[lson].ms,T[rson].ms);
  if(T[lson].rn<T[rson].ln){
    if(T[lson].ls==T[lson].cnt)
      T[t].ls+=T[rson].ls;
    if(T[rson].rs==T[rson].cnt)
      T[t].rs+=T[lson].rs;
    T[t].ms=Max(T[t].ms,T[lson].rs+T[rson].ls);
  }
}

void build(int t,int L,int R){
  T[t].cnt=R-L+1;
  if(L==R){
    T[t].ls=T[t].rs=T[t].ms=1;
    scanf("%d",&T[t].ln);
    T[t].rn=T[t].ln;
    return;
  }
  int mid=(L+R)>>1;
  build(lson,L,mid);
  build(rson,mid+1,R);
  push_up(t);
}

void update(int t,int L,int R,int x,int c){
  if(L==R){
    T[t].ln=T[t].rn=c;
    return;
  }
  int mid=(L+R)>>1;
  if(x<=mid)update(lson,L,mid,x,c);
  else update(rson,mid+1,R,x,c);
  push_up(t);
}

int query(int t,int L,int R,int l,int r){
  if(l<=L&&R<=r)return T[t].ms;
  int mid=(L+R)>>1,ans=0;
  if(l<=mid)ans=Max(ans,query(lson,L,mid,l,r));
  if(r>mid)ans=Max(ans,query(rson,mid+1,R,l,r));
  if(T[lson].rn<T[rson].ln)
    ans=Max(ans,Min(mid-l+1,T[lson].rs)+Min(r-mid,T[rson].ls));//
  return ans;
}

int main(){
  int t,n,m,l,r,x,c;
  char op[5];
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d",&n,&m);
      build(1,1,n);
      while(m--){
        scanf("%s",op);
        if(op[0]=='U'){
          scanf("%d%d",&x,&c);
          update(1,1,n,x+1,c);
        }else{
          scanf("%d%d",&l,&r);
          printf("%d\n",query(1,1,n,l+1,r+1));
        }
      }
    }
  }
}
