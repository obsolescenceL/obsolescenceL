/*************************************************************************
     File Name: POJ1655.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年09月11日 星期五 21时46分26秒
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
const int N=20010,INF=0x3f3f3f3f;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N<<1];
int dp[N],top,ans,min_maxn,n;

void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

void dfs(int ch,int pre){
  dp[ch]=1;
  for(Edge *p=head[ch];p;p=p->next)
    if(p->to != pre)
      dfs(p->to,ch),dp[ch]+=dp[p->to];
  //cout<<"dp["<<ch<<"]="<<dp[ch]<<endl;
}

void tree_dp(int ch,int pre){
  int maxn=0;
  for(Edge *p=head[ch];p;p=p->next)
    if(p->to != pre){
      tree_dp(p->to,ch);
      maxn=Max(maxn,dp[p->to]);
      //cout<<"~~~ maxn="<<maxn<<" dp["<<p->to<<"]="<<dp[p->to]<<endl;
    }
  maxn=Max(maxn,n-dp[ch]);
  //cout<<"maxn="<<maxn<<endl;
  //cout<<"dp["<<ch<<"]="<<dp[ch]<<endl;
  if(min_maxn > maxn)min_maxn=maxn,ans=ch;
}

int main(){
  int t,p1,p2,i;
  while(~scanf("%d",&t)){
    while(t--){
      top=0,Mem0(head),min_maxn=INF;
      scanf("%d\n",&n);
      for(i=1;i<n;++i){
        scanf("%d%d",&p1,&p2);
        Addedge(p1,p2),Addedge(p2,p1);
      }
      dfs(1,-1),tree_dp(1,-1);
      printf("%d %d\n",ans,min_maxn);
    }
  }
}
