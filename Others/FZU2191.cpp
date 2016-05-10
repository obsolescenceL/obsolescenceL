/*************************************************************************
     File Name: FZU2191.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 二  5/10 22:01:02 2016
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
  ios::sync_with_stdio(0);
  ll a,b,i,sum1,sum2,tmp;
  while(cin>>a>>b){
    sum1=sum2=0;
    for(i=1;i<=a-1;++i){
      tmp=(a-1)/(i*i)-i+1;
      if(tmp<=0)break;
      sum1+=tmp;
    }
    for(i=1;i<=b;++i){
      tmp=b/(i*i)-i+1;
      if(tmp<=0)break;
      sum2+=tmp;
    }
    cout<<sum2-sum1<<endl;
  }
}
