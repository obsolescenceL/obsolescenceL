/*************************************************************************
     File Name: D_zlh.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日  1/ 3 18:39:42 2016
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
const int N=100010;
map<int,int> mp;
int maxn,n;

bool solve(){
  int cnt=0,tmp=maxn,cur=maxn;
  while(cnt!=n){
    if(mp[tmp]){
      cur=tmp;
      mp[tmp--]--;
      cnt++;
    }else if(mp[tmp+2]){
      cur=tmp+2;
      mp[tmp+2]--;
      tmp++;
      cnt++;
    }else return 0;
  }
  if(cur==maxn-1)return 1;
  return 0;
}

int main(){
  int x,i;
  while(~scanf("%d",&n)){
    mp.clear();
    maxn=-1;
    for(i=0;i<n;++i){
      scanf("%d",&x);
      mp[x]++;
      maxn=Max(maxn,x);
    }
    if(solve())puts("YES");
    else puts("NO");
  }
}
