/*************************************************************************
    > File Name: UVA10110.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 5日 10:58:27
 ************************************************************************/
#include<cstdio>
#include<cmath>
int main(){
  long long n,s;
  while(~scanf("%lld",&n)&&n){
    s=(long)sqrt(n);
    if(s*s==n)puts("yes");
    else puts("no");
  }
}
