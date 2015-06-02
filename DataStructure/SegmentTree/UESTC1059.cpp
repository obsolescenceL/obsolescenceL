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
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define pb push_back
using namespace std;
const int N=100001*2;
struct node{
  ll sum;
  int add;
}tree[N<<2];
struct node2{
  int l,r,c;
  node2(int _l,int _r,int _c):l(_l),r(_r),c(_c){}
};
queue<int> q1,q2;
queue<node2> q3;
map<int,int> id;

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
  int i,n,m,op,l,r,c,x;
  while(~scanf("%d%d",&n,&m)){
    Mem0(tree),id.clear();
    vector<int> v;
    for(i=0;i<m;++i){
      scanf("%d",&op);
      q1.push(op);
      if(op){
        scanf("%d",&x);
        v.pb(x),q2.push(x);
      }else{
        scanf("%d%d%d",&l,&r,&c);
        v.pb(l),v.pb(r);
        q3.push(node2(l,r,c));
      }
    }
    n=v.size();
    sort(v.begin(),v.end());
    int ID=0;
    for(i=0;i<v.size();++i)
      if(!id.count(v[i]))id[v[i]]=++ID;
      else n--;
    while(m--){
      op=q1.front();q1.pop();
      if(op){
        x=id[q2.front()];q2.pop();
        printf("%lld\n",query(1,1,n,x));
      }else{
        l=id[q3.front().l];
        r=id[q3.front().r];
        c=q3.front().c;
        q3.pop();
        update(1,1,n,l,r,c);
      }
    }
  }
}
