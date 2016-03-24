/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  3/19 19:25:58 2016
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
#define ll long long
using namespace std;
const int N=200001,mod=1e9+7;
int a[N];

int main(){
  int t,i,n,k;
  ios::sync_with_stdio(0);
  cin>>t;
  while(t--){
    cin>>n>>k;
    ll limit=(ll)k*(k+1)/2;
    if(n<limit){
      cout<<"-1\n";
      continue;
    }
    ll tmp=n-(limit-k);
    ll x=tmp/k,left=tmp%k,ans=1;
    for(i=k-1;i>=0;--i){
      if(left)ans*=(ll)i+x+1,left--;
      else ans*=(ll)i+x;
      ans%=mod;
    }
    cout<<ans<<endl;
  }
}
