/*************************************************************************
     File Name: H.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月12日 星期二 14时59分01秒
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
const int N=1e5+10;
bool fd[N],fr[N];

int main(){
  int t,n,d,r,i,ans,pd,pr;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d%d",&n,&d,&r);
      Mem0(fd),Mem0(fr);
      ans=1;
      pd=d%n,pr=r%n;
      fd[pd]=1,fr[pr]=1;
      while(!fd[pr] && !fr[pd]){
        pd=(pd+d)%n,pr=(pr+r)%n;
        fd[pd]=1,fr[pr]=1;
        ans++;
      }
      printf("%d\n",ans);
    }
  }
}
