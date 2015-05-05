/*************************************************************************
     File Name: g.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月04日 星期一 20时33分58秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define Min(x,y) ((x)<(y)?(x):(y))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
ll a[200001];

int main(){
  int t;
  ll n,m,ans,i,j,temp;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%I64d%I64d",&n,&m);
      Mem0(a);
      ans=n*m;
      for(i=Min(n,m);i>1;--i){
        temp=(n/i)*(m/i);
        for(j=2*i;j<=Min(n,m);j+=i)
          temp-=a[j];
        a[i]=temp;
        ans-=a[i];
      }
      printf("%I64d\n",ans);
    }
  }
}
