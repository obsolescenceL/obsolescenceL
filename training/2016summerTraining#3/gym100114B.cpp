/*************************************************************************
     File Name: B.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月22日 星期五 13时38分57秒
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
const int N=1010;
char mp[N][N];

int main(){
  int n,m,i,j;
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  while(~scanf("%d%d",&n,&m)){
    for(i=1;i<=n;++i)
      scanf("%s",mp[i]+1);
    int ans=0;
    for(i=1;i<=n;++i)
      for(j=1;j<=m;++j)
        if(mp[i][j]=='+' && (mp[i][j-1]=='-' || mp[i][j+1]=='-' || mp[i-1][j]=='-' || mp[i+1][j]=='-'))ans++;
    printf("%d\n",ans);
  }
}
