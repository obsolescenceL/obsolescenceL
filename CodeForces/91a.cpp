/*************************************************************************
     File Name: 91a.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月05日 星期五 09时28分29秒
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
  vector<int> v;
  v.pb(4);
  v.pb(7);
  v.pb(44);
  v.pb(47);
  v.pb(74);
  v.pb(77);
  v.pb(444);
  v.pb(447);
  v.pb(474);
  v.pb(744);
  v.pb(477);
  v.pb(747);
  v.pb(774);
  v.pb(777);
  int n;
  bool flag=0;
  scanf("%d",&n);
  for(int i=0;v[i];++i)
    if(n%v[i]==0){
      flag=1;
      break;
    }
  if(flag)
    puts("YES");
  else puts("NO");
}
