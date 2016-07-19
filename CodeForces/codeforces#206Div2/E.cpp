/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月19日 星期二 10时45分20秒
 ************************************************************************/
#include<bits/stdc++.h>
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
const int N=300010,INF=0x3f3f3f3f;
int a[N];

int main(){
  int n,k,i,j,pos1,pos2;
  while(~scanf("%d%d",&n,&k)){
    for(i=0;i<n;++i)
      scanf("%d",a+i);
    sort(a,a+n);
    if(a[0]<=k+1){
      printf("%d\n",a[0]);
      continue;
    }
    for(i=a[0];i>k;--i){
      int cnt=0;
      for(j=1;j*i+k<=a[n-1]+i;++j){
        pos1=lower_bound(a,a+n,j*i)-a;
        pos2=lower_bound(a,a+n,j*i+k+1)-a;
        cnt+=pos2-pos1;
      }
      if(cnt==n)break;
    }
    printf("%d\n",i);
  }
}
