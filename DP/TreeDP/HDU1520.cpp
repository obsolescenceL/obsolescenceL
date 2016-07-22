/*************************************************************************
     File Name: HDU1520.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年09月16日 星期三 21时17分12秒
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
const int N=7000;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N<<1];
int dp[N][2],v[N],top;
  
void Addegde(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

void tree_dp(int ch,int pre){
  dp[ch][1]=v[ch];
  for(Edge *p=head[ch];p;p=p->next)
    if(p->to != pre){
      tree_dp(p->to,ch);
      dp[ch][1]+=dp[p->to][0];
      dp[ch][0]+=Max(dp[p->to][1],dp[p->to][0]);
      //cout<<"dp["<<ch<<"][1]="<<dp[ch][1]<<" dp["<<ch<<"][0]="<<dp[ch][0]<<endl;
    }
}

int main(){
  int n,i,p1,p2;
  while(~scanf("%d",&n)){
    Mem0(head),Mem0(dp),top=0;
    for(i=1;i<=n;++i)scanf("%d",v+i);
    while(scanf("%d%d",&p1,&p2)&&(p1||p2))
      Addegde(p1,p2),Addegde(p2,p1);
    tree_dp(1,-1);
    printf("%d\n",Max(dp[1][0],dp[1][1]));
  }
}
