/*************************************************************************
     File Name: J.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日 11/ 8 15:56:22 2015
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
int lis[N],lds[N],a[N],v[N];

int main(){
  int i,j,n;
  while(~scanf("%d",&n)){
    for(i=0;i<n;++i){
      scanf("%d",a+i);
      lis[i]=lds[i]=1;
    }
    int pos,max_l=0;
    for(i=0;i<n;++i){
      pos=lower_bound(v,v+max_l,a[i])-v;
      lis[i]=pos+1;
      v[pos]=a[i];
      max_l=Max(max_l,pos+1);
    }
    max_l=0;
    for(i=n-1;i>=0;--i){
      pos=lower_bound(v,v+max_l,a[i])-v;
      lds[i]=pos+1;
      v[pos]=a[i];
      max_l=Max(max_l,pos+1);
    }
    int lws=0;
    for(i=0;i<n;++i)
      lws=Max(lws,Min(lis[i],lds[i]));
    lws=lws*2-1;
    printf("%d\n",lws);
  }
}
