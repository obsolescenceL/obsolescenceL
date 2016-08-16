/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月15日 星期五 10时43分08秒
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
const int N=310;
int a[N],b[N];
bool flag[N];

int main(){
  int n,m,k,i,j;
  while(~scanf("%d%d%d",&n,&m,&k)){
    Mem0(flag);
    for(i=1;i<=k;++i){
      scanf("%d",a+i);
      flag[a[i]]=1;
    }
    if(m>(n-k)*k+(n-k)*(n-k-1)/2){
      puts("-1");
      continue;
    }
    for(i=j=1;i<=n;++i)
      if(!flag[i])b[j++]=i;
    for(i=1;i<=k && m;++i)
      for(j=1;j<=n-k && m;++j){
        printf("%d %d\n",a[i],b[j]);
        m--;
      }
    for(i=1;i<=n-k && m;++i)
      for(j=1;j<=n-k && m;++j){
        if(i==j)continue;
        printf("%d %d\n",b[i],b[j]);
        m--;
      }
  }
}
