/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月27日 星期五 00时33分06秒
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
using namespace std;
long long a[100001];


int main(){
  int n,i;
  long long sum;
  while(~scanf("%d",&n)){
    sum=0;
    for(i=0;i<n;++i){
      scanf("%I64d",a+i);
      sum+=a[i];
    }
    if(sum%4)

  }
}
