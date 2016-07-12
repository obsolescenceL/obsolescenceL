/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  4/ 2 13:42:17 2016
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
const int N=3010,INF=0x3f3f3f3f;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N*2];
int dis[N][N],top;

void Addedge(int from,int to){
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

void spfa(int s){
  queue<int> q;
  bool vis[N];
  Mem0(vis);
  dis[s][s]=0;
  q.push(s);
  vis[s]=1;
  int x,to;
  while(!q.empty()){
    x=q.front();
    q.pop();
    vis[x]=0;
    for(Edge *p=head[x];p;p=p->next){
      to=p->to;
      if(dis[s][to]>dis[s][x]+1){
        dis[s][to]=dis[s][x]+1;
        if(!vis[to]){
          vis[to]=1;
          q.push(to);
        }
      }
    }
  }
}

int main(){
  int n,m,i,j,p1,p2,s1,t1,l1,s2,t2,l2;
  ios::sync_with_stdio(0);
  while(cin>>n>>m){
    MemX(dis);
    Mem0(head),top=0;
    for(i=0;i<m;++i){
      cin>>p1>>p2;
      Addedge(p1,p2);
      Addedge(p2,p1);
    }
    for(i=1;i<=n;++i)spfa(i);
    cin>>s1>>t1>>l1>>s2>>t2>>l2;
    int ans=INF,d1,d2;
    for(i=1;i<=n;++i)
      for(j=1;j<=n;++j){
        d1=dis[s1][i]+dis[i][j]+dis[j][t1];
        d2=dis[s2][i]+dis[i][j]+dis[j][t2];
        if(d1<=l1 && d2<=l2)
          ans=Min(ans,d1+d2-dis[i][j]);
        d1=dis[s1][i]+dis[i][j]+dis[j][t1];
        d2=dis[s2][j]+dis[i][j]+dis[i][t2];
        if(d1<=l1 && d2<=l2)
          ans=Min(ans,d1+d2-dis[i][j]);
      }
    if(dis[s1][t1]<=l1 && dis[s2][t2]<=l2)
      ans=Min(ans,dis[s1][t1]+dis[s2][t2]);
    if(ans==INF)cout<<"-1\n";
    else cout<<m-ans<<endl;
  }
}
