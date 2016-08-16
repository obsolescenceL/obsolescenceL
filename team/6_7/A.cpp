/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月07日 星期日 14时09分02秒
 ************************************************************************/
#include<cstdio>
#include<bitset>
using namespace std;
const int N=5000001;

int main(){
  int t,n,i,x,sum;
  scanf("%d",&t);
  while(t--){
    bitset<N> a,b;
    sum=0;
    scanf("%d",&n);
    for(i=1;i<=2*(n-1);++i){
      scanf("%d",&x);
      sum^=x;
      a.set(x);
      b.flip(x);
    }
    if(sum){
      for(i=1;i<=n;++i)
        if(b.test(i))break;
      x=i;
      for(i=x+1;i<=n;++i)
        if(b.test(i))break;
      printf("%d %d\n",x,i);
    }else{
      for(i=1;i<=n;++i)
        if(!a.test(i))break;
      printf("%d %d\n",i,i);
    }
  }
}
