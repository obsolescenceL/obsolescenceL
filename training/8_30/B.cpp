/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月30日 星期日 20时24分02秒
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
const int N=4010,INF=0x3f3f3f3f;
bool adj[N][N];
int r[N];

int main(){
  int n,m,i,j,k,u,v;
  while(~scanf("%d%d",&n,&m)){
    Mem0(adj),Mem0(r);
    while(m--){
      scanf("%d%d",&u,&v);
      adj[u][v]=adj[v][u]=1;
      r[u]++,r[v]++;
    }
    int min_rs=INF;
    for(i=1;i<=n-2;++i)
      for(j=i+1;j<=n-1;++j){
        if(!adj[i][j])continue;
        for(k=j+1;k<=n;++k)
          if(adj[i][k] && adj[j][k])
            min_rs=Min(min_rs,r[i]+r[j]+r[k]);
      }
    if(min_rs!=INF)printf("%d\n",min_rs-6);
    else puts("-1");
  }
}
