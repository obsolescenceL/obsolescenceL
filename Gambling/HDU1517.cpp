/*************************************************************************
     File Name: HDU1517.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月16日 星期六 15时01分23秒
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
  ll n,nn;
  while(~scanf("%lld",&n)){
    nn=n;
    int cnt=0;
    while(n!=1){
      n=ceil(n/18.0);
      cnt++;
    }
    ll tmp=pow(9.0,cnt)*pow(2.0,cnt-1);
    //cout<<"tmp="<<tmp<<endl;
    if(nn>tmp)puts("Ollie wins.");
    else puts("Stan wins.");
    //cout<<"cnt="<<cnt<<endl;
  }
}
