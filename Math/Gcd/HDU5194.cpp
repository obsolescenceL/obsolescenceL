/*************************************************************************
     File Name: 1001.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月28日 星期六 19时01分42秒
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
string s;


int main(){
  ios::sync_with_stdio(0);
  int n,m,i;
  while(cin>>n>>m){
    int a=n*m,b=n+m;
    int t=__gcd(a,b);
    printf("%d/%d\n",a/t,b/t);
  }
}
