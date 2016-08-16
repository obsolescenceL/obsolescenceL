/*************************************************************************
     File Name: POJ2761.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月23日 星期四 9时25分02秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100010;
struct node{
  int ls,rs,cnt;
}tree[N*20];
int cur,root[N],num[N],snum[N];

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
  if(L==R)return L;
  int mid=(L+R)>>1,ans=tree[tree[r].ls].cnt-tree[tree[l].ls].cnt;
  if(kth<=ans)return query(L,mid,tree[l].ls,tree[r].ls,kth);
  else return query(mid+1,R,tree[l].rs,tree[r].rs,kth-ans);
}

int main(){
  int n,m,l,r,kth,i,cnt,pos;
  while(~scanf("%d%d",&n,&m)){
    init();
    for(i=1;i<=n;++i)
      scanf("%d",num+i),snum[i]=num[i];
    sort(snum+1,snum+n+1);
    for(cnt=1,i=2;i<=n;++i)
      if(snum[i]!=snum[cnt])
        snum[++cnt]=snum[i];
    root[0]=build(1,cnt);
    for(i=1;i<=n;++i){
      pos=lower_bound(snum+1,snum+cnt+1,num[i])-snum;
      root[i]=update(root[i-1],1,cnt,pos,1);
    }
    while(m--){
      scanf("%d%d%d",&l,&r,&kth);
      pos=query(1,cnt,root[l-1],root[r],kth);
      printf("%d\n",snum[pos]);
    }
  }
}
