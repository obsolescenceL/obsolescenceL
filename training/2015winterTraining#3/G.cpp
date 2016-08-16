/*************************************************************************
     File Name: G.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月13日 星期三 14时06分59秒
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
struct node{
  int to;
  node *next;
}*head[N],e[N];
int n,top,inde[N];
int pre[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};

void Addedge(int from,int to){
  node *p=&e[top++];
  p->to=to,p->next=head[from],head[from]=p;
}

int Dfs(){
  int sum=0,cnt1=0,cnt2=0,i;
  for(i=1;i<=n;++i)
    if(inde[i]==-1)cnt1++;
    else if(!inde[i])cnt2++;
  if(cnt1+cnt2==n){
    cnt1=pre[cnt2];
    for(i=13;i<=cnt2;++i)
      cnt1*=i,cnt1%=mod;
    return cnt1;
  }
  for(i=1;i<=n;++i){
    if(!inde[i]){
      inde[i]=-1;
      for(node *p=head[i];p;p=p->next)
        inde[p->to]--;
      sum+=Dfs();
      sum%=mod;
      for(node *p=head[i];p;p=p->next)
        inde[p->to]++;
      inde[i]=0;
    }
  }
  if(!sum)sum=1;
  return sum%mod;
}

int main(){
  int t,i;
  while(~scanf("%d",&t)){
    for(int nc=1;nc<=t;++nc){
      scanf("%d",&n);
      Mem0(head),Mem0(inde);
      top=0;
      for(i=1;i<n;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        inde[b]++;
        Addedge(a,b);
      }
      printf("Case %d: %d\n",nc,Dfs());
    }
  }
}
