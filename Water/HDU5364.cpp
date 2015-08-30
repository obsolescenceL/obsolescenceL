/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月08日 星期六 18时35分00秒
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
int num[N],cnt[N*10];

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    Mem0(cnt);
    int maxn=0,pos;
    for(i=1;i<=n;++i){
      scanf("%d",num+i);
      cnt[num[i]]++;
      if(maxn<cnt[num[i]])
        maxn=cnt[num[i]],pos=num[i];
    }
    if(maxn*2>n)printf("%d\n",pos);
    else puts("-1");
  }
}
