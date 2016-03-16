/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 三  3/16 19:38:49 2016
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
const int N=510;
int ans[N][N];

int main(){
  int n,k,i,j;
  while(~scanf("%d%d",&n,&k)){
    int top=0,res=0;
    for(i=0;i<n;++i)
      for(j=0;j<k-1;++j)
        ans[i][j]=++top;
    for(i=0;i<n;++i)
      for(j=k-1;j<n;++j)
        ans[i][j]=++top;
    for(i=0;i<n;++i)
      res+=ans[i][k-1];
    printf("%d\n",res);
    for(i=0;i<n;++i){
      for(j=0;j<n-1;++j)
        printf("%d ",ans[i][j]);
      printf("%d\n",ans[i][j]);
    }
  }
}
