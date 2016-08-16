/*************************************************************************
     File Name: UVALive5818.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年02月11日 星期四 18时54分55秒
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
const int N=110;
struct node{
  int to;
  node *next;
}*head[N],e[N*N];
int top,v[N];

void Addedge(int from,int to){
  node *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

int main(){
  int t,n,m,p1,p2,i;
  while(~scanf("%d",&t)){
    for(int nc=1;nc<=t;++nc){
      Mem0(head),top=0;
      scanf("%d%d",&n,&m);
      for(i=0;i<n;++i)scanf("%d",v+i);
      while(m--){
        scanf("%d%d",&p1,&p2);
        Addedge(p1,p2);
      }
      int ans=0,maxp=0;
      node *p=head[0];
      while(p){
        //cout<<"p->to="<<(p->to)<<endl;
        for(;p;p=p->next)
          if(v[maxp]<v[p->to])
            maxp=p->to;
        ans+=v[maxp];
        p=head[maxp];
        //cout<<"maxp="<<maxp<<endl;
        v[maxp]=0;
      }
      printf("Case %d: %d %d\n",nc,ans,maxp);
    }
  }
}
