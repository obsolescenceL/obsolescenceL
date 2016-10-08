/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六 10/ 8 19:59:13 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=1e5+10,INF=0x3f3f3f3f;
char s[N];
struct node{
  int pos,x;
}tree[N<<2];
vector<char> v;
int cnt[30];

void pushUp(int t) {
  if (tree[t<<1].x<tree[t<<1|1].x) {
    tree[t].x=tree[t<<1].x;
    tree[t].pos=tree[t<<1].pos;
  } else {
    tree[t].x=tree[t<<1|1].x;
    tree[t].pos=tree[t<<1|1].pos;
  }
}

void update(int t,int L,int R,int x,int v) {
  if (L==R && L==x) {
    tree[t].x=v;
    tree[t].pos=x;
    return;
  }
  int mid=(L+R)>>1;
  if (x<=mid) update(t<<1,L,mid,x,v);
  else update(t<<1|1,mid+1,R,x,v);
  pushUp(t);
}

int main() {
  int m,i;
  cin>>m;
  cin>>s;
  MEMX(tree);
  int n=strlen(s),pos=-INF,mins=26;
  for (i=0; i<MIN(m-1,n); ++i) {
    update(1,1,n,i+1,s[i]-'a');
    cnt[s[i]-'a']++;
  }
  for (i=m-1; i<n; ++i) {
    cnt[s[i]-'a']++;
    update(1,1,n,i+1,s[i]-'a');
    if (i-m>=0)
      update(1,1,n,i-m+1,INF);
    //cout<<"i-m+1="<<i-m+1<<' ';
    //cout<<"i="<<i<<endl;
    if (pos>=i-m+1 && pos<=i) continue;
    pos=tree[1].pos-1;
    //cout<<"pos="<<pos<<endl;
    //cout<<"tree[1].x="<<tree[1].x<<endl;
    v.pb(s[pos]);
  }
  sort(v.begin(),v.end());
  i=0;
  char ans;
  while (v[v.size()-1]-'a'>i) {
    ans='a'+i;
    for (int j=0; j<cnt[i]; ++j)
      cout<<ans;
    ++i;
  }
  for (i=0; i<v.size()-1; ++i) 
    if (v[i]==v[v.size()-1]) break;
  for (; i<v.size(); ++i) cout<<v[i];
  cout<<endl;
}
