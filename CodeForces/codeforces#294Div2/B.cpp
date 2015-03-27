/*************************************************************************
     File Name: cf2.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月28日 星期六 21时33分37秒
 ************************************************************************/
#include<cstdio>

int main(){
  int n,i,ans1,ans2,x;
  long long a,b,c;
  while(~scanf("%d",&n)){
    a=b=c=0;
    for(i=0;i<n;++i)
      scanf("%d",&x),a+=x;
    for(i=0;i<n-1;++i)
      scanf("%d",&x),b+=x;
    for(i=0;i<n-2;++i)
      scanf("%d",&x),c+=x;
    printf("%I64d\n%I64d\n",a-b,b-c);
  }
}
