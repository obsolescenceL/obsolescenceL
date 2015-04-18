/*************************************************************************
     File Name: 4_4b.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月04日 星期六 11时44分58秒
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
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
using namespace std;
bool flag[10001][1000];
int n;

inline bool query(int x,int y){
  for(int i=0;i<n;++i)
    if(flag[x][i]&&flag[y][i])return 1;
  return 0;
}

int main(){
  int i,m,x,y;
  while(~scanf("%d",&n)){
    memset(flag,0,sizeof flag);
    for(i=0;i<n;++i){
      scanf("%d",&m);
      while(m--){
        scanf("%d",&x);
        flag[x][i]=1;
      }
    }
    scanf("%d",&m);
    while(m--){
      scanf("%d%d",&x,&y);
      printf("%s\n",query(x,y)?"Yes":"No");
    }
  }
}
