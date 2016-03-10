/*************************************************************************
     File Name: HDU1850.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月11日 星期一 12时11分14秒
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
int n[N],sum1[N],sum2[N];

int main(){
  int m,i;
  while(~scanf("%d",&m)&&m){
    int sum=0;
    Mem0(sum1),Mem0(sum2);
    for(i=1;i<=m;++i){
      scanf("%d",&n[i]);
      sum^=n[i];
      sum1[i]=sum1[i-1]^n[i];
      //cout<<"sum1["<<i<<"]="<<sum1[i]<<endl;
    }
    for(i=m;i>=1;--i){
      sum2[i]=sum2[i+1]^n[i];
      //cout<<"sum2["<<i<<"]="<<sum2[i]<<endl;
    }
    if(sum){
      int cnt=0;
      for(i=1;i<=m;++i){
        //cout<<"n["<<i<<"]="<<n[i]<<endl;
        //cout<<"sum1["<<i-1<<"]^sum2["<<i+1<<"]="<<(sum1[i-1]^sum2[i+1])<<endl;
        if(n[i]>=(sum1[i-1]^sum2[i+1]))
          cnt++;
      }
      printf("%d\n",cnt);
    }else puts("0");
  }
}
