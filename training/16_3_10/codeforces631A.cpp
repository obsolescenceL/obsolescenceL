/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 四  3/10 20:43:34 2016
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
const int N=1010;
int a[N],b[N];

int main(){
  int n,i,j;
  while(~scanf("%d",&n)){
    for(i=1;i<=n;++i)
      scanf("%d",&a[i]);
    for(i=1;i<=n;++i)
      scanf("%d",&b[i]);
    int maxn=0,tmp1,tmp2;
    for(i=1;i<=n;++i){
      tmp1=tmp2=0;
      for(j=i;j<=n;++j){
        tmp1|=a[j];
        tmp2|=b[j];
        maxn=Max(maxn,tmp1+tmp2);
        //cout<<"tmp1="<<tmp1<<" tmp2="<<tmp2<<endl;
        //cout<<"ans="<<tmp1+tmp2<<" i="<<i<<" j="<<j<<endl;
        //cout<<"---------------"<<endl;
      }
    }
    printf("%d\n",maxn);
  }
}
