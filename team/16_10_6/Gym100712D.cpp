/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 四 10/ 6 22:55:53 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1010;
int dp[N];
char s[N];

int main() {
  int t,n,k,i,j;
  cin>>t;
  for (int nc=1; nc<=t; ++nc) {
    cin>>n>>k>>s;
    MEMX(dp);
    dp[n]=0;
    for (i=n-1; i>=0; --i) {
      bool isAlter=0;
      for (j=i; j-i+1<=k && j<n; ++j) {
        if (j>i && s[j]==s[j-1]) isAlter=1;
        if (i==j || isAlter)
          dp[i]=MIN(dp[i],1+dp[j+1]);
      }
    }
    cout<<dp[0]-1<<endl;
  }
}
