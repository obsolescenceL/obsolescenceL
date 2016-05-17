/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 三  3/ 2 19:13:46 2016
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
const int N=10010;
struct node{
  int d_n,step;
}s,t;
bool vis[N];
int n,m;

bool bfs(){
  queue<node> q;
  Mem0(vis);
  q.push(s);
  vis[s.d_n]=1;
  while(!q.empty()){
    s=q.front();
    q.pop();
    if(!s.d_n){
      printf("%d\n",s.step);
      return 0;
    }
    for(int i=0;i<=Min(m,s.d_n);++i){
      t=s,t.step++,t.d_n-=i-m+i;//!!
      if(m-i<=n-t.d_n && !vis[t.d_n]){
        vis[t.d_n]=1;
        q.push(t);
      }
    }
  }
  return 1;
}

int main(){
  int t,x,i;
  while(~scanf("%d",&t)){
    while(t--){
      s.d_n=s.step=0;
      scanf("%d%d",&n,&m);
      for(i=0;i<n;++i){
        scanf("%d",&x);
        s.d_n+=x;
      }
      if(bfs())puts("Poor Girl");
    }
  }
}
