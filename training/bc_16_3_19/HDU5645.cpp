/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  3/19 19:10:37 2016
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
const int N=310;
int a[N];

int main(){
  //ios::sync_with_stdio(0);
  int t,n,i;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&n);
      for(i=0;i<n;++i){
        scanf("%d",a+i);
      }
      a[n]=0;
      sort(a,a+n,greater<int>());
      double ans=0.0;
      for(i=0;i<n-1;++i){
        int pos=upper_bound(a,a+n,a[i],greater<int>())-a;
        //cout<<"pos="<<pos<<endl;
        ans+=(double)n-pos;
        //cout<<"ans="<<ans<<endl;
      }
      printf("%.6f\n",ans/(n-1)/n);
    }
  }
}
