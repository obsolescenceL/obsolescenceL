/*************************************************************************
     File Name: G.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月20日 星期四 15时32分26秒
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
int a[N];

int main(){
  int n,i,j,temp,sum,max_sum;
  while(~scanf("%d",&n)){
    sum=max_sum=0;
    for(i=1;i<=n;++i){
      scanf("%d",&a[i]);
      if(a[i])sum++;
    }
    for(i=1;i<=n;++i){
      temp=0;
      for(j=i;j<=n;++j){
        if(!a[j])temp++;
        max_sum=Max(max_sum,sum+temp-(j-i+1-temp));
      }
    }
    printf("%d\n",max_sum);
  }
}
