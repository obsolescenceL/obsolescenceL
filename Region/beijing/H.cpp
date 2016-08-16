/*************************************************************************
     File Name: H.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年09月20日 星期日 16时13分09秒
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
  int t;
  double k;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%lf",&k);
      //cout<<"k="<<k<<endl;
      if(k==0.5){
        puts("1002");
        continue;
      }else if(k==0){
        puts("-1");
        continue;
      }
      ll x=(ll)(k*1e8);
      ll m=25000000;
      int cnt=1;
      while(x>=m){
        cout<<"-------------"<<endl;
        cout<<"x="<<x<<endl;
        cout<<"m="<<m<<endl;
        cnt++;
        x-=m,m/=2;
        if(m%2)x*=10,m*=10;
      }
      if(!x)puts("-1");
      else printf("%d\n",cnt*4);
    }
  }
}
