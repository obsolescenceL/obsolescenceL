/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月28日 星期四 10时58分42秒
 ************************************************************************/
//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#define left t<<1
#define right t<<1|1
using namespace std;
const int N=100010;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N<<1];
int hash1[N],hash2[N],top,tot,ans,tree[N<<2];

void AddEdge(int from,int to) {
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

void dfs(int ch,int pre) {
  ++tot;
  hash1[ch]=tot;
  //cout<<"ch="<<ch<<" pre="<<pre<<" tot="<<tot<<endl;
  for (Edge *p=head[ch]; p; p=p->next) {
    if (p->to!=pre) dfs(p->to,ch);
  }
  hash2[ch]=tot;
}

void pushUp(int t) {
  tree[t]=tree[left]+tree[right];
}

void build(int t,int L,int R) {
  if (L==R) {
    tree[t]=1;
    return;
  }
  int mid=(L+R)>>1;
  build(left,L,mid);
  build(right,mid+1,R);
  pushUp(t);
}

void update(int t,int L,int R,int x) {
  if (L==R) {
    tree[t]^=1;
    return;
  }
  int mid=(L+R)>>1;
  if (x<=mid) update(left,L,mid,x);
  if (x>mid) update(right,mid+1,R,x);
  pushUp(t);
}

void query(int t,int L,int R,int l,int r) {
  if (l<=L && R<=r) {
    ans+=tree[t];
    return;
  }
  int mid=(L+R)>>1;
  if (l<=mid) query(left,L,mid,l,r);
  if (r>mid) query(right,mid+1,R,l,r);
}

int main() {
  int n,m,i,p1,p2,x;
  char op[2];
  while (~scanf("%d",&n)) {
    Mem0(head),top=0,tot=0;
    for (i=1; i<n; ++i) {
      scanf("%d%d",&p1,&p2);
      //cout<<"p1="<<p1<<" p2="<<p2<<endl;
      AddEdge(p1,p2);
      AddEdge(p2,p1);
    }
    dfs(1,-1);
    //for (i=1; i<=n; ++i)
      //cout<<hash2[i]<<' ';
    //cout<<endl;
    build(1,1,n);
    scanf("%d",&m);
    while (m--) {
      scanf("%s%d",op,&x);
      if (op[0]=='Q') {
        ans=0;
        query(1,1,n,hash1[x],hash2[x]);
        printf("%d\n",ans);
      } else {
        update(1,1,n,hash1[x]);
      }
    }
  }
}
