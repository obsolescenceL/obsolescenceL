/*************************************************************************
     File Name: HDU3586.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月29日 星期六 10时47分33秒
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
const int N=1010,INF=1e6+10;//!!!!!
struct Edge{
  int to,w;
  Edge *next;
}*head[N<<1],e[N<<1];
int dp[N],top;
bool vis[N];

void Addedge(int from,int to,int w){
  Edge *p=&e[++top];
  p->to=to,p->w=w,p->next=head[from],head[from]=p;
}

void dfs(int to,int limit){
  if(vis[to])return;
  vis[to]=1;
  int tmp=0;
  bool flag=0;
  for(Edge *p=head[to];p;p=p->next){
    if(!vis[p->to]){
      flag=1;
      dfs(p->to,limit);
      if(p->w > limit)tmp+=dp[p->to];
      else tmp+=Min(dp[p->to],p->w);
    }
  }
  if(flag)dp[to]=tmp;
  else dp[to]=INF;
  //cout<<"dp["<<to<<"]="<<dp[to]<<endl;
}

int main(){
  int n,m,i,p1,p2,w,max_w,ans;
  while(~scanf("%d%d",&n,&m)&&(n||m)){
    //cout<<"n="<<n<<" m="<<m<<endl;
    ans=-1,max_w=0,top=0;
    Mem0(head);
    for(i=1;i<n;++i){
      scanf("%d%d%d",&p1,&p2,&w);
      //cout<<"p1="<<p1<<" p2="<<p2<<" w="<<w<<endl;
      Addedge(p1,p2,w);
      max_w=Max(max_w,w);
    }
    int low=1,high=max_w,mid;
    while(low<=high){
      //cout<<"low="<<low<<" high="<<high<<endl;
      Mem0(dp),Mem0(vis);
      mid=low+(high-low)/2;
      //cout<<"mid="<<mid<<endl;
      dfs(1,mid);
      if(dp[1]<=m){
        ans=mid,high=mid-1;
        //cout<<"ans="<<ans<<endl;
      }else low=mid+1;
    }
    printf("%d\n",ans);
  }
}
