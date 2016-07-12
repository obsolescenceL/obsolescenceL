/*************************************************************************
     File Name: HDU3333.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五  4/22 22:40:57 2016
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
#define right (t<<1|1)
#define left (t<<1)
using namespace std;
const int N=30010,M=1e5+10;
int a[N];
struct node{
  int l,r,id;
  bool operator < (const node& rhs)const{
    return r<rhs.r || (r==rhs.r && l<rhs.l);
  }
}q[M];
map<ll,int> mp;
ll tree[N<<2],ans[M],res;

void push_up(int t){
  tree[t]=tree[left]+tree[right];
}

void update(int t,int L,int R,int x,int v){
  if(L==R){
    tree[t]+=v;
    return;
  }
  int mid=(L+R)>>1;
  if(x<=mid)update(left,L,mid,x,v);
  else update(right,mid+1,R,x,v);
  push_up(t);
}

void query(int t,int L,int R,int l,int r){
  if(r<l)return;
  if(l<=L && R<=r){
    res+=tree[t];
    return;
  }
  int mid=(L+R)>>1;
  if(l<=mid)query(left,L,mid,l,r);
  if(r>mid)query(right,mid+1,R,l,r);
}

int main(){
  ios::sync_with_stdio(0);
  int t,n,m,i,l,r;
  while(cin>>t){
    while(t--){
      Mem0(tree);
      mp.clear();
      cin>>n;
      for(i=1;i<=n;++i)
        cin>>a[i];
      //scanf("%d",&m);
      cin>>m;
      for(i=0;i<m;++i){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
      }
      sort(q,q+m);
      int pos=1;
      for(i=0;i<m;++i){
        for(;pos<=q[i].r;++pos){
          //cout<<"a["<<pos<<"]="<<a[pos]<<endl;
          if(mp[a[pos]]){
            update(1,1,n,mp[a[pos]],-a[pos]);
          }
          update(1,1,n,pos,a[pos]);
          mp[a[pos]]=pos;
        }
        res=0;
        query(1,1,n,q[i].l,q[i].r);
        //cout<<"q["<<i<<"].l="<<q[i].l<<' ';
        //cout<<"q["<<i<<"].r="<<q[i].r<<endl;
        //cout<<"res="<<res<<endl;
        ans[q[i].id]=res;
      }
      for(i=0;i<m;++i)
        cout<<ans[i]<<endl;
    }
  }
}
