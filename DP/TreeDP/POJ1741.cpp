/*************************************************************************
     File Name: POJ1741.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年09月18日 星期五 20时05分09秒
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
const int N=10010,INF=0x3f3f3f3f;
struct Edge{
  int to,w;
  Edge *next;
}*head[N],e[N<<1];

int max_sz[N],hash[N],num[N],max_n[N],dis[N],tot,top,k,ans,root;
bool vis[N];


void Addedge(int from,int to,int w){
  Edge *p=&e[++top];
  p->to=to,p->w=w,p->next=head[from],head[from]=p;
}

void dfs(int to,int pre){
  num[to]=1,max_n[to]=0;
  //cout<<"to="<<to<<" pre="<<pre<<endl;
  for(Edge *p=head[to];p;p=p->next)
    if(p->to!=pre && !vis[p->to]){
      dfs(p->to,to);
      num[to]+=num[p->to];
      max_n[to]=Max(max_n[to],num[p->to]);
    }
  hash[++tot]=to,max_sz[tot]=max_n[to];
}

int get_root(int to){
  tot=0,dfs(to,-1);
  int minn=INF,r;
  for(int i=1;i<=tot;++i){
    max_sz[i]=Max(max_sz[i],num[to]-max_sz[i]);
    if(max_sz[i] < minn)
      minn=max_sz[i],r=hash[i];
  }
  return r;
}

void get_dis(int to,int pre,int d){
  dis[++tot]=d;
  for(Edge *p=head[to];p;p=p->next)
    if(p->to != pre && !vis[p->to] && d+p->w <= k)
      get_dis(p->to,to,d+p->w);
}

void count_1(){
  sort(dis+1,dis+1+tot);
  int l=1,r=tot;
  while(l < r)
    if(dis[l]+dis[r] <= k){
      ans+=r-l,l++;
      //cout<<"r="<<r<<" l="<<l<<endl;
    }else r--;
}

void count_3(){
  sort(dis+1,dis+1+tot);
  int l=1,r=tot;
  while(l < r)
    if(dis[l]+dis[r] <= k){
      ans-=r-l,l++;
      //cout<<"r="<<r<<" l="<<l<<endl;
    }else r--;
}

void count_2(int to){
  vis[to]=1;
  for(Edge *p=head[to];p;p=p->next)
    if(!vis[p->to]){
      tot=0,get_dis(p->to,to,p->w);
      count_3();
    }
}

void solve(int to,int pre){
  root=get_root(to);
  tot=0,get_dis(root,-1,0);
  count_1(),count_2(root);
  //cout<<"ans="<<ans<<endl;
  for(Edge *p=head[root];p;p=p->next)
    if(p->to!=pre && !vis[p->to])
      solve(p->to,root);
  //cout<<"-------------"<<endl;
}

int main(){
  int n,p1,p2,w;
  while(~scanf("%d%d",&n,&k)&&(n||k)){
    //cout<<"n="<<n<<" k="<<k<<endl;
    Mem0(head),Mem0(vis),top=ans=0;
    n--;
    while(n--){
      scanf("%d%d%d",&p1,&p2,&w);
      //cout<<"p1="<<p1<<" p2="<<p2<<" w="<<w<<endl;
      Addedge(p1,p2,w);
      Addedge(p2,p1,w);
    }
    solve(1,-1);
    //cout<<"-------------"<<endl;
    printf("%d\n",ans);
  }
}
