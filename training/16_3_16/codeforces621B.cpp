/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 三  3/16 19:47:05 2016
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
const int N=2010;
int cnt1[N],cnt2[N];

int main(){
  int n,i,x,y;
  ios::sync_with_stdio(0);
  while(cin>>n){
    Mem0(cnt1),Mem0(cnt2);
    for(i=0;i<n;++i){
      cin>>x>>y;
      cnt1[x-y+1000]++;
      cnt2[x+y]++;
    }
    ll ans=0;
    for(i=0;i<=2000;++i){
      ans+=(ll)cnt1[i]*(cnt1[i]-1)/2;
      ans+=(ll)cnt2[i]*(cnt2[i]-1)/2;
    }
    cout<<ans<<endl;
  }
}
