/*************************************************************************
     File Name: d.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月26日 星期日 21时16分17秒
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
  int n,h,i,nc=0,ans;
  while(~scanf("%d",&n)){
    stack<int> s;
    ans=0;
    while(n--){
      scanf("%d",&h);
      //cout<<"h="<<h<<endl;
      while(!s.empty() && s.top()>h)
        ans++,s.pop();
      //cout<<"ans="<<ans<<endl;
      if((!s.empty() && s.top()<h) || (s.empty() && h))s.push(h);
      //cout<<"s.size="<<s.size()<<endl;
    }
    while(!s.empty())ans++,s.pop();
    printf("Case %d: %d\n",++nc,ans);
  }
}
