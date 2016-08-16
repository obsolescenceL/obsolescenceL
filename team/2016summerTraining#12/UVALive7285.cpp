/*************************************************************************
     File Name: B.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月05日 星期五 12时39分00秒
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
const int N=110;
char mp[N][N];
int num[N][N],mx[]={0,0,1,-1,},my[]={1,-1,0,0};
bool vis[N][N];
struct node{
  int x,y;
  node(int _x,int _y):x(_x),y(_y){};
}s(0,0),t(0,0);

int main() {
  int n,m,i,j;
  while (~scanf("%d%d",&n,&m)) {
    Mem0(num),Mem0(vis);
    queue<node> q;
    for (i=1; i<=n; ++i) {
      scanf("%s",mp[i]+1);
      //cout<<mp[i]+1<<endl;
      for (j=1; j<=m; ++j)
        if (mp[i][j]=='.') {
          q.push(node(i,j));
          vis[i][j]=1;
        }
    }
    for (i=0; i<=n+1; ++i) {
      q.push(node(i,0));
      q.push(node(i,m+1));
    }
    for (i=0; i<=m+1; ++i) {
      q.push(node(0,i));
      q.push(node(n+1,i));
    }
    int max_num=0;
    while (!q.empty()) {
      s=q.front();
      q.pop();
      for (i=0; i<4; ++i) {
        t=s;
        t.x+=mx[i],t.y+=my[i];
        if (t.x<=0 || t.x>n || t.y<=0 || t.y>m) continue;
        if (vis[t.x][t.y]) continue;
        vis[t.x][t.y]=1;
        num[t.x][t.y]=num[s.x][s.y]+1;
        max_num=Max(max_num,num[t.x][t.y]);
        q.push(t);
      }
    }
    if (max_num>=10) {
      for (i=1; i<=n; ++i){
        for (j=1; j<=m; ++j)
          if (num[i][j]>=10)
            printf(".%d",num[i][j]);
          else if (num[i][j])
            printf("..%d",num[i][j]);
          else printf("...");
        puts("");
      }
    } else {
      for (i=1; i<=n; ++i){
        for (j=1; j<=m; ++j)
          if (num[i][j])
            printf(".%d",num[i][j]);
          else printf("..");
        puts("");
      }
    }
  }
}
