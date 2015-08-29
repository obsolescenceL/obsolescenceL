/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月27日 星期四 19时04分41秒
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
const int N=1e5+10;
int a[N],b[N];

int main(){
  int na,nb,k,m,i;
  while(~scanf("%d%d",&na,&nb)){
    scanf("%d%d",&k,&m);
    for(i=1;i<=na;++i)scanf("%d",a+i);
    for(i=1;i<=nb;++i)scanf("%d",b+i);
    sort(a+1,a+1+na);
    sort(b+1,b+1+nb);
    //cout<<"k="<<k<<" nb-m+1="<<nb-m+1<<endl;
    if(a[k]>=b[nb-m+1])puts("NO");
    else puts("YES");
  }
}
