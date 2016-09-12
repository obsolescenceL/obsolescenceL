/*************************************************************************
     File Name: 1010.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  9/10 14:06:01 2016
 ************************************************************************/
#pragma comment(linker, "/STACK:102400000,102400000")
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+10;
typedef long long LL;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N];

bool flag[N];
int pos[N],l[N],r[N],tot;
LL v[N],tree[20][N],sorted[N];
int toleft[20][N];
LL ans;

void AddEdge(int from,int to) {
  Edge *p=&e[++tot];
  p->to=to,p->next=head[from],head[from]=p;
}

void dfs(int ch,int pre) {
  //cout<<"--------------"<<endl;
  ++tot;
  l[ch]=tot;
  pos[tot]=ch;
  for (Edge *p=head[ch]; p; p=p->next) {
    if (p->to!=pre) dfs(p->to,ch);
  }
  r[ch]=tot;
}

void build(int l,int r,int dep) {
  if (l==r) return;
  int mid=(l+r)>>1;
  LL key=sorted[mid];
  int scnt=mid-l+1,i;
  for (i=l; i<=r; ++i)
    if (tree[dep][i]<key) --scnt;
  int lpos=l-1,rpos=mid,cnt=0;
  for (i=l; i<=r; ++i) {
    LL x=tree[dep][i];
    if (x<key || (x==key && scnt)) {
      if (x==key) --scnt;
      ++cnt;
      tree[dep+1][++lpos]=x;
    } else tree[dep+1][++rpos]=x;
    toleft[dep][i]=cnt;
  }
  build(l,mid,dep+1);
  build(mid+1,r,dep+1);
}

void query(int L,int R,int l,int r,int dep,LL k) {
  if (l>r) return; 
  if (l==r) {
    //cout<<"tree["<<dep<<"]["<<l<<"]="<<tree[dep][l]<<endl;
    if (tree[dep][l]<=k) ans++;
    return;
  }
  int mid=(L+R)>>1;
  LL key=sorted[mid];
  int left=0,sum_l=toleft[dep][r];
  if (L!=l) {
    left=toleft[dep][l-1];
    sum_l-=left;
  }
  if (key>k) {
    int newl=L+left;
    int newr=newl+sum_l-1;
    query(L,mid,newl,newr,dep+1,k);
  } else {
    int newl=mid+1+l-L-left;
    int newr=newl+r-l-sum_l;
    ans+=(LL)sum_l;
    query(mid+1,R,newl,newr,dep+1,k);
  }
}

int main() {
  int t,n,p1,p2,i;
  LL k;
  ios::sync_with_stdio(0);
  while (cin>>t) {
    while (t--) {
      tot=0;
      MEM0(flag), MEM0(head), MEM0(toleft);
      cin>>n>>k;
      for (i=1; i<=n; ++i) cin>>v[i];
      for (i=1; i<n; ++i) {
        cin>>p1>>p2;
        AddEdge(p1,p2);
        flag[p2]=1;
      }
      int root1=-1;
      for (i=1; i<=n; ++i) {
        if (flag[i]) continue;
        root1=i;
        break;
      }
      tot=0;
      dfs(root1,-1);
      for (i=1; i<=n; ++i)
        sorted[i]=tree[0][i]=v[pos[i]];
      sort(sorted+1,sorted+n+1);
      build(1,n,0);
      ans=0;
      for (i=1; i<=n; ++i) {
        if (l[i]<r[i]) {
          if (v[i]) {
            //cout<<"ans="<<ans<<endl;
            //cout<<"k/v["<<i<<"]="<<k/v[i]<<endl;
            //ans+=query(1,n,l[i]+1,r[i],0,k/v[i]);
            query(1,n,l[i]+1,r[i],0,k/v[i]);
            //cout<<"ans="<<ans<<endl;
            //cout<<"-------"<<endl;
          } else {
            //cout<<"ans="<<ans<<endl;
            ans+=r[i]-l[i];
            //cout<<"ans="<<ans<<endl;
          }
          //cout<<"l="<<l[i]+1<<" r="<<r[i]<<endl;
        }
      }
      cout<<ans<<endl;
    }
  }
}
