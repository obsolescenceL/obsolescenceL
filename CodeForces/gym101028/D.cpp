/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月12日 星期二 12时58分04秒
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
const int N=110;
char mp[N][N];

int main(){
  int t,n,m,q,i,j,x1,y1,x2,y2;
  char c[2];
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d%d",&n,&m,&q);
      Mem0(mp);
      while(q--){
        scanf("%d%d%d%d%s",&x1,&y1,&x2,&y2,c);
        for(i=x1;i<=x2;++i)
          for(j=y1;j<=y2;++j)
            mp[i][j]=c[0];
      }
      for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)
          if(mp[i][j])printf("%c",mp[i][j]);
          else printf(".");
        puts("");
      }
    }
  }
}
