/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  4/18 21:48:29 2016
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
using namespace std;
const int N=1e5+10;
struct node{
  int x,y,nu;
  bool operator < (const node& rhs)const{
    return nu>rhs.nu;
  }
}s,t;
int a[N],b[N],n,mx[]={0,1},my[]={1,0};
int ans;
pair<int,int> p;
map<pair<int,int>,int> vis;
priority_queue<node> q;

void bfs(){
  s.x=0,s.y=0,s.nu=a[0]+b[0];
  q.push(s);
  int cnt=0,i;
  while(cnt<n){
    s=q.top();q.pop();
    printf("%d\n",s.nu);
    cnt++;
    for(i=0;i<2;++i){
      t.x=s.x+mx[i];
      t.y=s.y+my[i];
      if(t.x>n || t.y>n)continue;
      p=make_pair(t.x,t.y);
      if(vis[p])continue;
      vis[p]=1;
      t.nu=a[t.x]+b[t.y];
      q.push(t);
    }
  }
}

int main(){
  int i,j,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;++i)scanf("%d",&a[i]);
  for(i=0;i<n;++i)scanf("%d",&b[i]);
  sort(a,a+n);
  sort(b,b+n);
  bfs();
}
