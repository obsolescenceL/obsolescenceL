/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日 11/ 8 14:26:57 2015
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
const int N=1000010;
int r[15],dp[N];

int main(){
  int n,m,i,j;
  while(~scanf("%d%d",&n,&m)){
    Mem0(dp);
    for(i=0;i<m;++i)
      scanf("%d",r+i);
    sort(r,r+m);
    for(j=1;j<=n;++j){
      for(i=0;i<m && r[i]<=j;++i){
        if(!dp[j-r[i]])dp[j]=1;
        //cout<<"dp["<<j-r[i]<<"]="<<dp[j-r[i]]<<' ';
        //cout<<"dp["<<j<<"]="<<dp[j]<<endl;
      }
    }
    //for(i=1;i<=n;++i) cout<<"dp["<<i<<"]="<<dp[i]<<endl;
    if(dp[n])puts("Stan wins");
    else puts("Ollie wins");
  }
}
