/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月13日 星期三 12时11分07秒
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
const int N=1010,mod=1e9+7;
struct Edge{
  int to;
  Edge* next;
}*head[N],e[N];
int top,inde[N],n;
ll dp[N];

void Addedge(int from,int to){
  Edge* p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

void Top(){
  priority_queue<int> q;
  int i,cnt=0;
  for(i=1;i<=n;++i)
    if(!inde[i]){
      q.push(i);
      cnt++;
    }
  while(!q.empty()){
    int x=q.top();
    cnt--,q.pop();
    for(Edge* p=head[x];p;p=p->next)
      if(--inde[p->to]==0)
        q.push(p->to),cnt++;
  }
}

int main(){
  int t,i,a,b;
  while(~scanf("%d",&t)){
    for(int nc=1;nc<=t;++nc){
      Mem0(head),top=0,ans=1;
      scanf("%d",&n);
      for(i=1;i<n;++i){
        scanf("%d%d",&a,&b);
        inde[b]++;
        Addedge(a,b);
      }
      Top();
      printf("Case %d: %lld\n",nc,ans);
    }
  }
}
