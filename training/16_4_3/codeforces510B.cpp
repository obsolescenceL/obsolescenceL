/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日  4/ 3 15:16:39 2016
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
const int N=55;
char mp[N][N];
struct node{
  int x,y,sx,sy,flag,step;
}s,t;
bool f,vis[N][N];
int n,m,mx[]={0,0,1,-1},my[]={1,-1,0,0};

void dfs(node s){
  for(int i=0;i< 4;++i){
    t=s;
    t.x+=mx[i],t.y+=my[i],t.step++;
    if(t.x==t.sx && t.y==t.sy && t.step>4){f=1;return;}
    if(t.x<0 || t.x>=n || t.y<0 || t.y>=m || vis[t.x][t.y])continue;
    if(mp[t.x][t.y]-'A'!=t.flag)continue;
    vis[t.x][t.y]=1;
    dfs(t);
  }
}

int main(){
  int i,j;
  ios::sync_with_stdio(0);
  while(cin>>n>>m){
    for(i=0;i<n;++i)
      cin>>mp[i];
    f=0;
    for(i=0;i<n;++i)
      for(j=0;j<m;++j){
        Mem0(vis);
        s.x=s.sx=i;
        s.y=s.sy=j;
        s.flag=mp[i][j]-'A';
        s.step=1;
        vis[i][j]=1;
        dfs(s);
      }
    if(f)cout<<"Yes\n";
    else cout<<"No\n";
  }
}
