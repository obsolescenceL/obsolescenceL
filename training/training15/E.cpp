/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月03日 星期一 12时30分08秒
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
const int N=1e5+10;
int num[N];

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    //int sum=0;
    for(i=0;i<n;++i){
      scanf("%d",&num[i]);
      //sum+=num[i];
      if(i)num[i]+=num[i-1];
    }
    int ans=0;
    for(i=0;i<n-1;++i)
      if(num[i]*2==num[n-1])ans++;
    printf("%d\n",ans);
  }
}
