/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月29日 星期六 19时13分11秒
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
const int N=1010;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N<<1];
struct node{
  int v,dis;
};
int top;
bool vis[N];
int num[N];

void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

int main(){
  int n,i,j,u,v;
  while(~scanf("%d",&n)){
    top=0;Mem0(vis),Mem0(num),Mem0(head);
    for(i=1;i<n;++i){
      scanf("%d%d",&u,&v);
      Addedge(u,v),Addedge(v,u);
    }
    node t,x;
    t.v=1,t.dis=0;
    queue<node> q;
    q.push(t);
    vis[t.v]=1;
    int max_dis=-1;
    while(!q.empty()){
      t=q.front();
      q.pop();
      for(Edge *p=head[t.v];p;p=p->next){
        int v=p->to;
        x.v=v,x.dis=t.dis+1;
        if(vis[v])continue;
        vis[v]=1;
        max_dis=Max(max_dis,x.dis);
        num[x.dis]++;
        q.push(x);
        //cout<<"p->to="<<p->to<<endl;
      }
      //cout<<"cnt="<<cnt<<endl;
      //if(cnt>1)break;
    }
    //cout<<"max_dis="<<max_dis<<endl;
    bool flag=1;
    for(i=1;i<max_dis;++i)
      if(num[i]>1)flag=0;
    if(flag)puts("YES");
    else puts("NO");
  }
}
