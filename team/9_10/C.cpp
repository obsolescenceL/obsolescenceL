/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年09月10日 星期四 13时32分36秒
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
char x[20];

int main(){
  int i;
  ios::sync_with_stdio(0);
  while(cin>>x){
    int len=strlen(x),cnt=-1,cnt2=0;
    bool flag=1;
    ll n=0;
    for(i=len-1;i>=0;--i){
      if(x[i]!='.'){
        cnt++;
        n+=(x[i]-'0')*pow(10.0,cnt);
      }else flag=0;
      if(flag)cnt2++;
    }
    if(!n){
      cout<<"0\n";
      continue;
    }
    if(!flag)cnt2+=2;
    ll m=pow(10.0,cnt2);
    //cout<<"n="<<n<<endl;
    //cout<<"m="<<m<<endl;
    //cout<<"cnt="<<cnt<<endl;
    ll g=__gcd(n,m);
    //cout<<"g="<<g<<endl;
    cout<<m/g<<endl;
  }
}
