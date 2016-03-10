/*************************************************************************
     File Name: HDU1686.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月27日 星期三 21时28分15秒
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
const int N=10010;
char w[N],t[N*100];
ll seed=131;

int BKDR_Hash(char *str,int len){
  ll hash=0;
  while(len--)
    hash=hash*seed+(*str++);
  return (hash & 0x7fffffff);
}

int main(){
  int T,i;
  while(~scanf("%d",&T)){
    while(T--){
      scanf("%s%s",w,t);
      int lenw=strlen(w),lent=strlen(t);
      ll keyw=BKDR_Hash(w,lenw);
      ll keyt=BKDR_Hash(t,lenw-1);
      int cnt=0;
      ll tmp=1;
      for(i=0;i<lenw;++i)tmp*=seed;
      for(i=lenw-1;i<lent;++i){
        keyt=(keyt*seed+t[i]-t[i-lenw]*tmp) & 0x7fffffff;
        if(keyw==keyt)cnt++;
      }
      printf("%d\n",cnt);
    }
  }
}
