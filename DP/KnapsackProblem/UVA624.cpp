/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五 11/ 6 18:46:04 2015
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
const int N=25,M=10000;
int c[N],dp[M];
bool path[N][M];

int main(){
  int n,m,i,j;
  while(~scanf("%d%d",&m,&n)){
    Mem0(dp),Mem0(path);
    for(i=1;i<=n;++i){
      scanf("%d",c+i);
      //cout<<c[i]<<' ';
    }
    //cout<<endl;
    for(i=n;i>0;--i)
      for(j=m;j>=c[i];--j){
        int temp=dp[j-c[i]]+c[i];
        if(dp[j]<temp)
          dp[j]=temp,path[i][j]=1;
      }
    for(i=1,j=m;i<=n;++i)
      if(path[i][j]){
        printf("%d ",c[i]);
        j-=c[i];
      }
    printf("sum:%d\n",dp[m]);
  }
}
