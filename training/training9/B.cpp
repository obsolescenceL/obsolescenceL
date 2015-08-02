/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月28日 星期二 13时54分36秒
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
  int n,s,f,ans;
  while(~scanf("%d%d%d",&n,&s,&f)){
    ans=0;
    if(s>f)swap(s,f);
    if(f-s==1){
      if(s>1 && f<n)puts("-1");
      else puts("1");
    }else{
      if(s>1)ans++,s++;
      if(f<n)ans++,f--;
      ans+=(f-s)/3+(f-s)%3;
      printf("%d\n",ans);
    }
  }
}
