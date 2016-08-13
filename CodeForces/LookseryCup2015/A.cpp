/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月06日 星期六 20时54分27秒
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

bool is_ok(int i,int j){
  set<char> s;
  s.insert(mp[i][j]);
  s.insert(mp[i][j+1]);
  s.insert(mp[i+1][j]);
  s.insert(mp[i+1][j+1]);
  if(s.count('f')&&s.count('a')&&s.count('c')&&s.count('e'))return 1;
  return 0;
}

int main(){
  int n,m,i,j;
  while(~scanf("%d%d",&n,&m)){
    for(i=0;i<n;++i)
      scanf("%s",mp[i]);
    int ans=0;
    for(i=0;i<n-1;++i)
      for(j=0;j<m-1;++j)
        if(is_ok(i,j))ans++;
    printf("%d\n",ans);
  }
}
