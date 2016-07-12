/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日  4/ 3 15:53:48 2016
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
const int N=200010;
int a[N];

int main(){
  int n,i;
  ios::sync_with_stdio(0);
  while(cin>>n){
    for(i=0;i<n;++i)
      cin>>a[i];
    sort(a,a+n);
    int ans=a[n/2]-a[0];
    for(i=1;i<n/2;++i)
      ans=Min(ans,a[n/2+i]-a[i]);
    cout<<ans<<endl;
  }
}
