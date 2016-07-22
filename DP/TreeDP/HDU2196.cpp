/*************************************************************************
     File Name: HDU2196.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年09月18日 星期五 14时30分39秒
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
struct Edge{
  ll to,v,sum;
  Edge *next;
}*head[N],e[N<<1];
ll dp[N],top;

void Addedge(int from,int to,int v){
  Edge *p=&e[++top];
  p->to=to,p->v=v,p->next=head[from],head[from]=p;
}

void dfs(int ch,int pre){
  for(Edge *p=head[ch];p;p=p->next)
    if(p->to != pre){
      dfs(p->to,ch);
      dp[ch]=Max(dp[ch],dp[p->to]+p->v);
      p->sum=dp[p->to]+p->v;
      //cout<<"ch="<<ch<<endl;
      //cout<<"p->sum="<<p->sum<<"  dp["<<p->to<<"]="<<dp[p->to]<<"  p->v="<<p->v<<endl;
    }
  //cout<<"head["<<ch<<"]="<<head[ch]->sum<<endl;
}

void tree_dp(int ch,int pre){
  Edge *p;
  int max_another=0;
  for(p=head[pre];p;p=p->next)
    if(p->to != ch)
      max_another=Max(max_another,p->sum);
  //cout<<"ch="<<ch<<endl;
  //cout<<"max_another="<<max_another<<endl;
  for(p=head[ch];p;p=p->next)
    if(p->to == pre){
      p->sum=p->v+max_another;
      //cout<<"p->sum="<<p->sum<<endl;
      break;
    }
  for(p=head[ch];p;p=p->next){
    dp[ch]=Max(dp[ch],p->sum);
    if(p->to != pre){
      //cout<<"dp["<<ch<<"]="<<dp[ch]<<endl;
      tree_dp(p->to,ch);
    }
  }
}

int main(){
  int n,i,p,v;
  while(~scanf("%d",&n)){
    Mem0(head),top=0,Mem0(dp);
    for(i=2;i<=n;++i){
      scanf("%d%d",&p,&v);
      Addedge(p,i,v),Addedge(i,p,v);
    }
    dfs(1,-1);
    for(Edge *p=head[1];p;p=p->next)
      tree_dp(p->to,1);
    //tree_dp(1,-1);

    for(i=1;i<=n;++i)
      printf("%I64d\n",dp[i]);
  }
}
