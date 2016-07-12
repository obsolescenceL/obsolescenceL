/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  3/12 19:09:54 2016
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
  int t,n,m;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d",&n,&m);
      int ans=0;
      while(n>0 && m>0){
        if(n<m)swap(n,m);
        //cout<<"n="<<n<<" m="<<m<<endl;
        ans+=n/m;
        n%=m;
      }
      printf("%d\n",ans);
    }
  }
}
