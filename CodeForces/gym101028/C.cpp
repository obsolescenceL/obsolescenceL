/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月12日 星期二 12时57分48秒
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
const int N=110,mod=1e9+7;
char a[N],b[N];

int main(){
  int t,n,i;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%s%s",&n,a,b);
      //cout<<a<<endl<<b<<endl;
      ll ans=1;
      for(i=0;i<n && ans;++i){
        if(a[i]=='1'){
          if(b[i]=='1')ans=(ans*2)%mod;
          else ans=0;
        }
      }
      if(ans)printf("%I64d\n",ans);
      else puts("IMPOSSIBLE");
    }
  }
}
