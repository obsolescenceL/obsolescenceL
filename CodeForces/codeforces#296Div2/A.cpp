/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月18日 星期三 00时29分37秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;


int main(){
  long long a,b;
  while(~scanf("%I64d%I64d",&a,&b)){
    long long ans=0;
    /*
    while(1){
      ans+=10000;
      printf("%lld\n",ans);
    }
    */
    while(b){
      //cout<<"gege"<<endl;
      //long long c=a/b;
      ans+=a/b;
      a%=b;
      //cout<<"a="<<a<<" b="<<b<<endl;
      //printf("ans=%lld\n",ans);
      if(a<b)swap(a,b);
    }
    printf("%I64d\n",ans);
  }
}
