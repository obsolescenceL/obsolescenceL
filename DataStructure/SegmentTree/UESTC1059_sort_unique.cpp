/*************************************************************************
     File Name: UESTC1059.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月22日 星期五 20时31分16秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
using namespace std;
const int N=100001*2;
struct node{
  ll sum;
  int add;
}tree[N<<2];
struct node2{
  int op,l,r,c;
}q[N];
int p[N],num;

int get_id(int x){
  return lower_bound(p+1,p+num+1,x)-p;
}

void push_up(int t){
  tree[t].sum=tree[t<<1].sum+tree[t<<1|1].sum;
}

void push_down(int t,int L,int R){
  if(!tree[t].add)return;
  int mid=(L+R)>>1;
  tree[t<<1].sum+=(ll)tree[t].add*(mid-L+1);
  tree[t<<1|1].sum+=(ll)tree[t].add*(R-mid);
  tree[t<<1].add+=tree[t].add;
  tree[t<<1|1].add+=tree[t].add;
  tree[t].add=0;
}

void update(int t,int L,int R,int l,int r,int c){
  if(l<=L&&R<=r){
    tree[t].sum+=(ll)c*(R-L+1);
    tree[t].add+=c;
    return;
  }
  push_down(t,L,R);
  int mid=(L+R)>>1;
  if(l<=mid)update(t<<1,L,mid,l,r,c);
  if(r>mid)update(t<<1|1,mid+1,R,l,r,c);
  push_up(t);
}

ll query(int t,int L,int R,int x){
  if(L==R)return tree[t].sum;
  push_down(t,L,R);
  int mid=(L+R)>>1;
  if(x<=mid)return query(t<<1,L,mid,x);
  else return query(t<<1|1,mid+1,R,x);
}

int main(){
  int i,n,m;
  while(~scanf("%d%d",&n,&m)){
    Mem0(tree);num=0;
    for(i=1;i<=m;++i){
      scanf("%d%d",&q[i].op,&q[i].l);
      p[++num]=q[i].l;
      if(!q[i].op){
        scanf("%d%d",&q[i].r,&q[i].c);
        p[++num]=q[i].r;
      }
    }
    sort(p+1,p+num+1);
    num=unique(p+1,p+num+1)-(p+1);
    for(i=1;i<=m;++i)
      if(q[i].op)
        printf("%lld\n",query(1,1,num,get_id(q[i].l)));
      else
        update(1,1,num,get_id(q[i].l),get_id(q[i].r),q[i].c);
  }
}
