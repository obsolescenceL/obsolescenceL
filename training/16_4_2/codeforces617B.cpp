/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  4/ 2 13:04:11 2016
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
const int N=110;
int a[N];

int main(){
  int n,i;
  ios::sync_with_stdio(0);
  while(cin>>n){
    int cnt=-1;
    for(i=0;i<n;++i){
      cin>>a[i];
      if(a[i])cnt++;
    }
    if(cnt==-1)cout<<"0\n";
    else{
      ll ans=1,tmp;
      for(i=0;i<n && !a[i];++i);
      int pos=i+1;
      while(cnt--){
        tmp=1;
        while(!a[pos++])tmp++;
        ans*=tmp;
      }
      cout<<ans<<endl;
    }
  }
}
