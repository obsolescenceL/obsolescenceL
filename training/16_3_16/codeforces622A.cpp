/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 三  3/16 20:20:28 2016
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

int main(){
  ll n,nn,tmp;
  int i;
  ios::sync_with_stdio(0);
  while(cin>>n){
    nn=n<<1;
    nn=sqrt((double)nn);
    //cout<<nn<<endl;
    for(i=nn;i>0;--i){
      tmp=(ll)i*(i+1)/2;
      //cout<<tmp<<endl;
      if(tmp<=n)break;
    }
    if(tmp==n)cout<<i<<endl;
    else cout<<n-tmp<<endl;
    //cout<<nn*(nn+1)/2<<endl;
  }
}
