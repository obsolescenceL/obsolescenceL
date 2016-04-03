/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  3/ 7 16:51:52 2016
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
int a[N],cnt[N];

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    Mem0(cnt);
    for(i=0;i<n;++i){
      scanf("%d",&a[i]);
      cnt[a[i]]++;
    }
    int nn=n,ans=0;
    while(nn){
      int tmp=0;
      for(i=1;i<=1000;++i)
        if(cnt[i])tmp++,cnt[i]--;
      ans+=tmp-1;
      nn-=tmp;
    }
    printf("%d\n",ans);
  }
}
