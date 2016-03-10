/*************************************************************************
     File Name: POJ3261.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年02月01日 星期一 13时22分20秒
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
const int N=20010,M=262143;
struct node{
  ll to;
  node *next;
}*head[M],e[N];
int s[N],top;
ll seed=31,hash[N];

ll BKDR_Hash(int *ss,int len){
  ll h=0;
  while(len--)h=h*seed+(*ss++);
  return h;
}

void Addedge(ll h){
  int from=h&M;
  node *p=&e[++top];
  p->to=h,p->next=head[from],head[from]=p;
}

int find(ll h){
  int from=h&M,cnt=0;
  for(node *p=head[from];p;p=p->next)
    if(p->to==h)cnt++;
  return cnt;
}

int main(){
  int n,k,i,ans;
  while(~scanf("%d%d",&n,&k)){
    for(i=0;i<n;++i)
      scanf("%d",&s[i]);
    int low=0,high=n-1,mid;
    while(low<=high){
      Mem0(head),top=0;
      ll tmp=1;
      mid=(low+high)>>1;
      hash[0]=BKDR_Hash(s,mid);
      Addedge(hash[0]);
      for(i=0;i<mid;++i)tmp*=seed;
      for(i=mid;i<n;++i){
        hash[i-mid+1]=hash[i-mid]*seed+s[i]-s[i-mid]*tmp;
        Addedge(hash[i-mid+1]);
      }
      bool flag=0;
      for(i=0;i<=n-mid && !flag;++i)
        if(find(hash[i])>=k)flag=1;
      if(flag)ans=mid,low=mid+1;
      else high=mid-1;
    }
    printf("%d\n",ans);
  }
}
