/*************************************************************************
     File Name: H.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月20日 星期四 15时56分52秒
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
const int N=105;
int my[N],vy[N];
bool adj[N][N];
int nx,ny,by[N],gl[N];

bool dfs(int x){
  for(int y=1;y<=ny;++y)
    if(adj[x][y] && !vy[y]){
      vy[y]=1;
      if(!my[y] || dfs(my[y])){
        my[y]=x;
        return 1;
      }
    }
  return 0;
}

int main(){
  int i,j;
  while(~scanf("%d",&nx)){
    Mem0(adj),Mem0(my);
    for(i=1;i<=nx;++i)
      scanf("%d",&by[i]);
    scanf("%d",&ny);
    for(i=1;i<=ny;++i)
      scanf("%d",&gl[i]);
    for(i=1;i<=nx;++i)
      for(j=1;j<=ny;++j)
        if(by[i]==gl[j] || by[i]+1==gl[j] || gl[j]+1==by[i])adj[i][j]=1;
    int cnt=0;
    for(int x=1;x<=nx;++x){
      Mem0(vy);
      if(dfs(x))cnt++;
    }
    printf("%d\n",cnt);
  }
}
