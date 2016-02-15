/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年02月03日 星期三 15时32分04秒
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
const int N=110;
char s[N];

int main(){
  int i,len,cnt1,cnt0,cnt01;
  while(~scanf("%s",s)){
    len=strlen(s);
    cnt0=cnt1=cnt01=0;
    for(i=0;i<len;++i)
      if(s[i]=='0'){
        cnt0++;
        if(s[(i+1)%len]=='1')cnt01++;
      }
    cnt1=len-cnt0;
    int tmp1=cnt01*len,tmp2=cnt0*cnt1;
    if(tmp1==tmp2)puts("EQUAL");
    else if(tmp1<tmp2)puts("SHOOT");
    else puts("ROTATE");
  }
}
