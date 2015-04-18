/*************************************************************************
     File Name: 4_4g.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月04日 星期六 16时00分57秒
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
#define Abs(x,y) ((x)>(y)?(x-y):(y-x))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
using namespace std;
int a[3001];
bool flag[3001];

bool is_ok(int n){
  for(int i=1;i<n;++i)
    if(!flag[i])return 0;
  return 1;
}

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    memset(flag,0,sizeof flag);
    scanf("%d",a);
    for(i=1;i<n;++i){
      scanf("%d",&a[i]);
      flag[Abs(a[i],a[i-1])]=1;
    }
    is_ok(n)?puts("Jolly"):puts("Not jolly");
  }
}
