/*************************************************************************
     File Name: POJ2104.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月12日 星期日 14时14分27秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100010;
struct Node{
  int ls,rs,cnt;//l_son,r_son
}tree[N*20];
int cur,root[N];

void init(){
  cur=0;
}

void push_up(int t){
  tree[t].cnt=tree[tree[t].ls].cnt+tree[tree[t].rs].cnt;
}

int build(int L,int R){
  int t=cur++;
  if(L==R){
    tree[t].cnt=0;
    return t;
  }
  int mid=(L+R)>>1;
  tree[t].ls=build(L,mid);
  tree[t].rs=build(mid+1,R);
  push_up(t);
  return t;
}

int update(int k,int L,int R,int x,int v){
  int t=cur++;
  tree[t]=tree[k];
  if(L==R){
    tree[t].cnt+=v;
    return t;
  }
  int mid=(L+R)>>1;
  if(x<=mid)tree[t].ls=update(tree[k].ls,L,mid,x,v);
  else tree[t].rs=update(tree[k].rs,mid+1,R,x,v);
  push_up(t);
  return t;
}

int query(int L,int R,int l,int r,int kth){
  if(R==L)return L;
  int mid=(L+R)>>1;
  int ans=tree[tree[r].ls].cnt-tree[tree[l].ls].cnt;
  if(kth<=ans)return query(L,mid,tree[l].ls,tree[r].ls,kth);
  else return query(mid+1,R,tree[l].rs,tree[r].rs,kth-ans);
}

int num[N],sort_num[N];

int main(){
  int n,m,l,r,kth,i;
  while(~scanf("%d%d",&n,&m)){
    init();
    for(i=1;i<=n;++i){
      scanf("%d",num+i);
      sort_num[i]=num[i];
    }
    sort(sort_num+1,sort_num+n+1);
    int cnt=1;
    for(i=2;i<=n;++i)//hash
      if(sort_num[i]!=sort_num[cnt])
        sort_num[++cnt]=sort_num[i];
    root[0]=build(1,cnt);
    for(i=1;i<=n;++i){
      int pos=lower_bound(sort_num+1,sort_num+cnt+1,num[i])-sort_num;//get address
      root[i]=update(root[i-1],1,cnt,pos,1);
    }
    while(m--){
      scanf("%d%d%d",&l,&r,&kth);
      int pos=query(1,cnt,root[l-1],root[r],kth);
      printf("%d\n",sort_num[pos]);
    }
  }
}
