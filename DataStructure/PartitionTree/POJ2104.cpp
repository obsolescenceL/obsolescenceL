/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 四  8/25 19:45:17 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=1e5+10,M=20;
struct node{
  int num[N],cnt[N];
}tree[M];
int sorted[N],ans;

void build(int t,int L,int R) {
  if (L==R) return;
  int mid=(L+R)>>1,key=sorted[mid],scnt=mid-L+1,i;
  for (i=L; i<=R; ++i)
    if (tree[t].num[i]<key) --scnt;
  int l=L-1,r=mid,cnt=0;
  for (i=L; i<=R; ++i) {
    int num=tree[t].num[i];
    if (num < key || (num == key && scnt)) {
      if (num == key) --scnt;
      ++cnt;
      tree[t+1].num[++l]=num;
    } else tree[t+1].num[++r]=num;
    tree[t].cnt[i]=cnt;
    //cout<<"tree["<<t<<"].cnt["<<i<<"]="<<cnt<<endl;
  }
  build(t+1,L,mid);
  build(t+1,mid+1,R);
}

void query(int t,int L,int R,int l,int r,int k) {
  if (L==R) {
    ans=tree[t].num[L];
    return;
  }
  int mid=(L+R)>>1,left=0,sum_l=tree[t].cnt[r],new_l,new_r;
  if (L != l) {
    left=tree[t].cnt[l-1];
    sum_l-=left;
  }
  if (sum_l >= k) {
    new_l=L+left;
    new_r=new_l+sum_l-1;
    query(t+1,L,mid,new_l,new_r,k);
  } else {
    new_l=mid+1+l-L-left;
    new_r=new_l+r-l-sum_l;
    query(t+1,mid+1,R,new_l,new_r,k-sum_l);
  }
}

int main() {
  int n,m,i,l,r,k;
  while (~scanf("%d%d",&n,&m)) {
    for (i=1; i<=n; ++i) {
      scanf("%d",sorted+i);
      tree[0].num[i]=sorted[i];
    }
    sort(sorted+1,sorted+n+1);
    build(0,1,n);
    while (m--) {
      scanf("%d%d%d",&l,&r,&k);
      query(0,1,n,l,r,k);
      //cout<<"------"<<endl;
      printf("%d\n",ans);
    }
  }
}
