/*************************************************************************
     File Name: C.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月27日 星期三 12时53分49秒
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
const int N=20010;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N<<1];
int top,n,dp[N],ans;

void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

void dfs(int ch,int pre){
  dp[ch]=1;
  for(Edge *p=head[ch];p;p=p->next)
    if(p->to!=pre)
      dfs(p->to,ch),dp[ch]+=dp[p->to];
}

void tree_dp(int ch,int pre){
  int sum=dp[ch]-1,tmp=0;
  for(Edge *p=head[ch];p;p=p->next){
    if(p->to!=pre){
      sum-=dp[p->to];
      tmp+=dp[p->to]*sum;
      tree_dp(p->to,ch);
    }
  }
  ans=Max(ans,(n-dp[ch])*(dp[ch]-1)+tmp);
  //cout<<"ch="<<ch<<" ans="<<ans<<endl;
}

int main(){
  int t,nc=0,i,p1,p2;
  while(~scanf("%d",&t)){
    while(t--){
      top=0,Mem0(head),Mem0(dp),ans=0;
      scanf("%d",&n);
      for(i=1;i<n;++i){
        scanf("%d%d",&p1,&p2);
        Addedge(p1,p2);
        Addedge(p2,p1);
      }
      dfs(1,-1);
      tree_dp(1,-1);
      printf("Case #%d: %d\n",++nc,ans);
    }
  }
}
