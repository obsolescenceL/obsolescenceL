/*************************************************************************
     File Name: J.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月28日 星期四 15时39分32秒
 ************************************************************************/
#include<bits/stdc++.h>
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
const int N=15;
char mp[N][N],dir[]={'U','R','D','L'};
bool vis[N][N][5],check[N][N];
int mx[]={-1,0,1,0},my[]={0,1,0,-1};
struct node{
  int x,y,step,d;
}s,t;

int main() {
  int h,w,i,j,k;
  while (~scanf("%d%d",&h,&w)) {
    Mem0(vis),Mem0(check);
    for (i=0; i<h; ++i) {
      scanf("%s",mp[i]);
      for (j=0; j<w; ++j)
        if (mp[i][j]!='.' && mp[i][j]!='*') {
          s.x=i,s.y=j,s.step=1;
          for (k=0; k<4; ++k)
            if (mp[i][j]==dir[k]) s.d=k;
        }
    }
    queue<node> q;
    q.push(s);
    check[s.x][s.y]=1;
    int ans=1;
    while (!q.empty()) {
      s=q.front();
      q.pop();
      ans=Max(ans,s.step);
      t=s,t.x+=mx[t.d],t.y+=my[t.d];
      int cnt=0;
      while (t.x<0 || t.x>=h || t.y<0 || t.y>=w) {
        cnt++;
        s.d=(s.d+1)%4;
        t=s,t.x+=mx[t.d],t.y+=my[t.d];
        if(cnt>=4)break;
      }
      if (t.x>=0 && t.x<h && t.y>=0 && t.y<w) {
        if (vis[t.x][t.y][t.d]) break;
        vis[t.x][t.y][t.d]=1;
        if (mp[t.x][t.y]!='*') {
          if (!check[t.x][t.y]) {
            t.step++;
            check[t.x][t.y]=1;
          }
          q.push(t);
        } else {
          s.d=(s.d+1)%4;
          q.push(s);
        }
      }
    }
    printf("%d\n",ans);
  }
}
