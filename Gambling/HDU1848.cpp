/*************************************************************************
     File Name: HDU1848.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年02月04日 星期四 19时18分03秒
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
int f[N],sg[N],mex[N];

void get_sg(int n){
  int i,j;
  Mem0(sg);
  for(i=1;i<=n;++i){
    Mem0(mex);
    for(j=1;f[j]<=i;++j)mex[sg[i-f[j]]]=1;
    for(j=0;j<=n;++j)
      if(!mex[j]){
        sg[i]=j;
        break;
      }
    //cout<<"-----------"<<endl;
  }
}

int main(){
  int m,n,p,i;
  f[0]=f[1]=1;
  for(i=2;i<=100;++i)
    f[i]=f[i-1]+f[i-2];
  get_sg(1000);
  while(~scanf("%d%d%d",&m,&n,&p)&&(m||n||p)){
    if(sg[m]^sg[n]^sg[p])puts("Fibo");
    else puts("Nacci");
  }
}
