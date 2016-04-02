/*************************************************************************
     File Name: G.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  4/ 2 13:42:37 2016
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
char mp[N][N];
bool vis[N][N];
struct node{
  int x,y;
}s,t;
int mx[]={0,0,1,-1},my[]={1,-1,0,0};
int n,m,ans[N][N],posx[N*N],posy[N*N];

void bfs(node s){
  queue<node> q;
  q.push(s);
  vis[s.x][s.y]=1;
  int cnt=0,i,j,top=0;
  while(!q.empty()){
    s=q.front();
    q.pop();
    posx[top]=s.x;
    posy[top++]=s.y;
    for(i=0;i<4;++i){
      t.x=s.x+mx[i];
      t.y=s.y+my[i];
      if(t.x<0 || t.x>=n || t.y<0 || t.y>=m || vis[t.x][t.y])continue;
      if(mp[t.x][t.y]=='.'){
        q.push(t);
        vis[t.x][t.y]=1;
      }else cnt++;
    }
  }
  for(i=0;i<top;++i)
    ans[posx[i]][posy[i]]=cnt;
}

int main(){
  int k,i,j,x,y;
  ios::sync_with_stdio(0);
  cin>>n>>m>>k;
  Mem1(ans);
  for(i=0;i<n;++i)
    cin>>mp[i];
  for(i=0;i<n;++i)
    for(j=0;j<m;++j)
      if(!vis[i][j] && mp[i][j]=='.')
        s.x=i,s.y=j,bfs(s);
  for(i=0;i<k;++i){
    cin>>x>>y;
    x--,y--;
    cout<<ans[x][y]<<endl;
  }
}
