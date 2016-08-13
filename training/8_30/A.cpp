/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月30日 星期日 19时04分51秒
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
int a[N];

int main(){
  int n,i,maxn,pos,vote;
  while(~scanf("%d",&n)){
    maxn=-1,vote=0;
    for(i=0;i<n;++i){
      scanf("%d",a+i);
      if(maxn<=a[i])
        maxn=a[i],pos=i;
    }
    if(!pos){puts("0");continue;}
    while(a[0]+vote<=maxn){
      a[pos]--,maxn--,vote++;
      for(i=1;i<n;++i)
        if(maxn<a[i])maxn=a[i],pos=i;
    }
    printf("%d\n",vote);
  }
}
