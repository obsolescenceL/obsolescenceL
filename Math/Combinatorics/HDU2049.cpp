/*************************************************************************
     File Name: HDU2049.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五  4/ 8 21:36:30 2016
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
const int N=20;
ll f[N+10];

ll C(int n,int m){
  ll sum=1;
  for(int i=1;i<=m;++i)
    sum=sum*(n-m+i)/i;
  return sum;
}

void init(){
  f[0]=1,f[1]=0,f[2]=1;
  for(int i=3;i<=N;++i)
    f[i]=(i-1)*(f[i-1]+f[i-2]);
}

int main(){
  init();
  int t,n,m;
  ios::sync_with_stdio(0);
  while(cin>>t){
    while(t--){
      cin>>n>>m;
      cout<<C(n,m)*f[m]<<endl;
    }
  }
}
