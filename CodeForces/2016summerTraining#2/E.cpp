/*************************************************************************
     File Name: E.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月20日 星期三 13时25分16秒
 ************************************************************************/
//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<map>
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
const int N=1010,M=1000010;
int p[M+10],k,res[N];
bool flag[3*M+8];

void sieve(){
  int i,j,l;
  for(i=2;i<=3*M+7;++i){
    if(!flag[i])p[k++]=i;
    for(j=0;i*p[j]<=3*M+7;++j){
      flag[i*p[j]]=1;
      if(i%p[j]==0)break;
    }
  }
  int cnt=0;
  for(i=30;cnt<N;++i){
    int cnt1=0;
    for(j=0;j<k;++j){
      if(i%p[j]==0)cnt1++;
      if(cnt1>=3){
        res[cnt++]=i;
        break;
      }
    }
  }
}

int main(){
  int t,n;
  sieve();
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&n);
      printf("%d\n",res[n-1]);
    }
  }
}
