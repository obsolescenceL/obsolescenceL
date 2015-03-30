/*************************************************************************
     File Name: 201409-1.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月25日 星期三 14时58分51秒
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
int a[1001];


int main(){
  int n;
  while(~scanf("%d",&n)){
    for(int i=0;i<n;++i){
      scanf("%d",a+i);
    }
    sort(a,a+n);
    int cnt=0;
    for(int i=1;i<n;++i){
      if(a[i]==a[i-1]+1)cnt++;
    }
    printf("%d\n",cnt);
  }
}
