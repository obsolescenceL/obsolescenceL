/*************************************************************************
     File Name: E.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月10日 星期三 14时53分53秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define LL long long
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=15;
bool mark[N][N];
int ans,n,m,t,cur[N][N],mx[]={0,0,1,-1},my[]={1,-1,0,0};

void dfs(int depth) {
  if (depth==t+1) { ans++;return; }
  int i,j,k,dx,dy;
  for (i=1; i<=n; ++i) {
    for (j=1; j<=m; ++j) {
      if (cur[i][j]) continue;
      bool flag=1;
      for (k=0; k<4 && flag; ++k) {
        dx=i+mx[k],dy=j+my[k];
        if (dx<=0 || dx>n || dy<=0 || dy>m)
          continue;
        if (mark[depth][cur[dx][dy]])
          flag=0;
      }
      if (flag) {
        cur[i][j]=depth;
        dfs(depth+1);
        cur[i][j]=0;
      }
    }
  }
}

int main() {
  int T,p,i,a,b;
  ios::sync_with_stdio(0);
  while (cin>>T) {
    while (T--) {
      MEM0(mark),MEM0(cur);
      cin>>n>>m>>t>>p;
      while (p--) {
        cin>>a>>b;
        mark[a][b]=mark[b][a]=1;
      }
      ans=0;
      dfs(1);
      if (ans) cout<<ans<<endl;
      else cout<<"impossible\n";
    }
  }
}
