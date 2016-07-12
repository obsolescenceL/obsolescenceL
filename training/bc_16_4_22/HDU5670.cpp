/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五  4/22 19:01:15 2016
 ************************************************************************/
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
const int N=33;
int flag[N];
char ch[]={'R','G','B'};

int main(){
  ios::sync_with_stdio(0);
  int t,m;
  ll n;
  while(cin>>t){
    while(t--){
      cin>>m>>n;
      int cnt=0;
      while(n && cnt<m){
        flag[cnt++]=n%3;
        n/=3;
      }
      if(m>cnt){
        m-=cnt;
        while(m--) cout<<'R';
      }
      while(cnt--)cout<<ch[flag[cnt]];
      cout<<endl;
    }
  }
}
