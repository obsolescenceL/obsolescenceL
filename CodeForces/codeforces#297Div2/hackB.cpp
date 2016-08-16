/*************************************************************************
     File Name: hack1.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月27日 星期五 02时06分47秒
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



int main(){
  //freopen("hack.out","w",stdout);
  const char a='a';
  for(int i=0;i<6999;++i){
    for(int j=0;j<27;++j){
      printf("%c",a+j);
    }
  }
  const int n=1e5-1;
  printf("\n%d\n",n);
  for(int i=0;i<n;++i){
    if(i)
      printf(" ");
    printf("1");
  }
}
