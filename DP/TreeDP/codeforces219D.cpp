/*************************************************************************
     File Name: codeforces219D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 四 10/ 1 15:21:38 2015
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
const int N=200010;
struct Edge{
  int to,w;
  Edge *next;
}*head[N],e[N<<1];
int dp[N],ans[N],top;

void Addedge(int from,int to,int w){
  Edge *p=&e[++top];
  p->to=to,p->w=w,p->next=head[from],head[from]=p;
}

void dfs(int ch,int pre){
  dp[ch]=0;
  for(Edge *p=head[ch];p;p=p->next){
    if(p->to != pre){
      dfs(p->to,ch);
      dp[ch]+=dp[p->to]+p->w;
    }
  }
  //cout<<"dp["<<ch<<"]="<<dp[ch]<<endl;
}

void tree_dp(int ch,int pre){
  for(Edge *p=head[ch];p;p=p->next)
    if(p->to != pre){
      if(p->w)dp[p->to]=dp[ch]-1;
      else dp[p->to]=dp[ch]+1;
      tree_dp(p->to,ch);
    }
}

int main(){
  int n,p1,p2,i;
  while(~scanf("%d",&n)){
    top=0,Mem0(head),Mem0(dp);
    for(i=1;i<n;++i){
      scanf("%d%d",&p1,&p2);
      Addedge(p1,p2,0);
      Addedge(p2,p1,1);
    }
    dfs(1,-1);
    tree_dp(1,-1);
    int minn=N;
    for(i=1;i<=n;++i){
      minn=Min(minn,dp[i]);
      //cout<<"dp["<<i<<"]="<<dp[i]<<endl;
    }
    printf("%d\n",minn);
    bool first=1;
    for(i=1;i<=n;++i)
      if(dp[i]==minn){
        if(first) printf("%d",i),first=0;
        else printf(" %d",i);
      }
    puts("");
  }
}
