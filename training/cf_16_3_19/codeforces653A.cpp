/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  3/19 16:34:28 2016
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
const int N=1010;
bool flag[N];

int main(){
  ios::sync_with_stdio(0);
  int n,x,i;
  while(cin>>n){
    Mem0(flag);
    for(i=0;i<n;++i){
      cin>>x;
      flag[x]=1;
    }
    bool f=0;
    for(i=1;i<=1000-2;++i){
      if(flag[i] && flag[i+1] && flag[i+2]){f=1;break;}
    }
    if(f)cout<<"YES\n";
    else cout<<"NO\n";
  }
}
