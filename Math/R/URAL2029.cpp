/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 四  8/18 16:04:53 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<iostream>
using namespace std;
const int N=60;
typedef long long ll;
ll pre[N];
char s[N];

void init() {
  pre[0]=1;
  for (int i=1; i<N; ++i) pre[i]=pre[i-1]*2;
}

int main() {
  int n,i;
  init();
  while (cin>>n>>s) {
    int cur=0,target;
    ll ans=0;
    for (i=n-1; i>=0; --i) {
      target=s[i]-'A';
      if (cur==target) continue;
      ans+=pre[i];
      cur=3-cur-target;
    }
    cout<<ans<<endl;
  }
}
