/*************************************************************************
     File Name: UESTC850.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月19日 星期二 14时52分35秒
 ************************************************************************/
#include<cstdio>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
struct node{
  ll m;
  int x;
  bool operator < (const node& rhs) const {
    return m>rhs.m;
  }
}s,t,e;
ll ans,n;

bool Bfs(){
  priority_queue<node> q;
  s.m=s.x=0;
  q.push(s);
  while(!q.empty()){
    t=q.top();
    q.pop();
    ll temp=(ll)pow(10,t.x);
    if(t.m*t.m%temp==n){
      ans=t.m;return 1;
    }
    for(int i=0;i<=9;++i){
      e.x=t.x+1,e.m=t.m+i*temp;
      if(e.m*e.m%(temp*10)==n%(temp*10))
        q.push(e);
    }
  }
  return 0;
}

int main(){
  int t;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%lld",&n);
      if(Bfs())printf("%lld\n",ans);
      else puts("None");
    }
  }
}
