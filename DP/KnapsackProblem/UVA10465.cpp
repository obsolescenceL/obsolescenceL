/*************************************************************************
     File Name: UVA10465.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六 11/ 7 21:22:10 2015
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
const int N=10010;
int dp[N],l[N];

int main(){
  int v[2],t,i,j;
  while(~scanf("%d%d%d",v,v+1,&t)){
    Mem0(dp);
    for(i=0;i<=t;++i)l[i]=i;
    for(i=0;i<2;++i)
      for(j=v[i];j<=t;++j){
        if(l[j]>l[j-v[i]]){
          dp[j]=dp[j-v[i]]+1;
          l[j]=l[j-v[i]];
        }else if(l[j]==l[j-v[i]])
          dp[j]=Max(dp[j],dp[j-v[i]]+1);
        /*if(dp[j]<dp[j-v[i]]+1){
          dp[j]=dp[j-v[i]]+1;
          l[j]=l[j-v[i]];
        }else if(dp[j]==dp[j-v[i]]+1){
          l[j]=Min(l[j],l[j-v[i]]);
        }
        */
        //cout<<"v["<<i<<"]="<<v[i]<<endl;

        //cout<<"dp["<<j<<"]="<<dp[j]<<' ';
        //cout<<"l["<<j<<"]="<<l[j]<<endl;
      }
        //cout<<"dp["<<t<<"]="<<dp[t]<<endl;
    printf("%d",dp[t]);
    if(l[t])printf(" %d\n",l[t]);
    else puts("");
  }
}
