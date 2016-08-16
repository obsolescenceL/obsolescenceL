/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月14日 星期四 17时52分01秒
 ************************************************************************/
#include<bits/stdc++.h>
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
const ll INF=0x3f3f3f3f3f3f3f3f;
ll dp[N],limit[N],cnt[N];
int top;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N<<1];

void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

void dfs(int ch,int pre){
  limit[ch]=1;
  cnt[ch]=0;
  for(Edge *p=head[ch];p;p=p->next)
    if(p->to!=pre){
      dfs(p->to,ch);
      ll g=__gcd(limit[ch],limit[p->to]);
      limit[ch]*=limit[p->to];
      limit[ch]/=g;//算的是最小公倍数
      cnt[ch]++;
    }
  if(cnt[ch])limit[ch]*=cnt[ch];
}

void tree_dp(int ch,int pre){
  ll minn=INF,tmp;
  for(Edge *p=head[ch];p;p=p->next){
    if(p->to!=pre){
      tree_dp(p->to,ch);
      minn=Min(minn,dp[p->to]);
      tmp=limit[ch]/cnt[ch];//tmp可能为0!!!
      if(tmp)minn-=minn%tmp;
    }
  }
  if(!dp[ch])dp[ch]=cnt[ch]*minn;
}

int main(){
  int n,i,p1,p2;
  while(~scanf("%d",&n)){
    top=0,Mem0(head);
    ll sum=0;
    for(i=1;i<=n;++i){
      scanf("%I64d",dp+i);
      sum+=dp[i];
    }
    for(i=1;i<n;++i){
      scanf("%d%d",&p1,&p2);
      Addedge(p1,p2);
      Addedge(p2,p1);
    }
    dfs(1,-1);
    tree_dp(1,-1);
    printf("%I64d\n",sum-dp[1]);
  }
}
