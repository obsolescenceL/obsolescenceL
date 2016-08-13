/*************************************************************************
     File Name: c.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月06日 星期六 20时54分50秒
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
int num[]={5,20,12,7,14,101};

int main(){
  int n,m,i,j,k;
  //while(~scanf("%d",&n,&m)){
  n=6,m=3;
  int odd=0,even=0;
  for(i=0;i<n;++i)
    for(j=i+1;j<n;++j)
      for(k=j+1;k<n;++k)
        if((num[i]+num[j]+num[k])%2)odd++;
        else even++;
  printf("odd=%d even=%d\n",odd,even);
}
