/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月27日 星期一 15时16分21秒
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
const int N=505;
char mp[4][N][N];
struct node{
  int x,y,step;
}s;
int n,m,ans[4],mx[]={1,-1,0,0},my[]={0,0,-1,1};
bool vis[N][N];

void bfs(int i){
  int j;
  Mem0(vis);
  queue<node> q;
  s.x=0,s.y=0,s.step=0;
  q.push(s);
  vis[s.x][s.y]=1;
  while(!q.empty()){
    s=q.front(),q.pop();
    if(s.x==n-1 && s.y==m-1){
      ans[i]=s.step;
      //cout<<"ans["<<i<<"]="<<ans[i]<<endl;
      return;
    }
    for(j=0;j<4;++j){
      node t;
      t.x=s.x+mx[j];
      t.y=s.y+my[j];
      t.step=s.step+1;
      if(0<=t.x&&t.x<n && 0<=t.y&&t.y<m && !vis[t.x][t.y] && mp[i][t.x][t.y]!='#'){
        //cout<<"t("<<t.x<<','<<t.y<<") "<<t.step<<endl;
        vis[t.x][t.y]=1;
        q.push(t);
      }
    }
  }
  ans[i]=-1;
}


int main(){
  int i,j;
  while(~scanf("%d%d",&n,&m)){
    for(i=0;i<n;++i)
      scanf("%s",mp[1]+i);
    for(i=0;i<n;++i)
      scanf("%s",mp[2]+i);
    for(i=0;i<n;++i)
      for(j=0;j<m;++j){
        mp[3][i][j]='.';
        if(mp[1][i][j]=='#'||mp[2][i][j]=='#') mp[3][i][j]='#';
      }
//    for(i=0;i<n;++i){
//      for(j=0;j<m;++j)
//        printf("%c",mp[3][i][j]);
//      puts("");
//    }
    for(i=1;i<=3;++i) bfs(i);
    //cout<<ans[1]<<' '<<ans[2]<<' '<<ans[3]<<endl;
    if(ans[1]!=-1 && ans[1]==ans[2] && ans[2]==ans[3])
      puts("YES");
    else puts("NO");
  }
}
