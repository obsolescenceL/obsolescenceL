/*************************************************************************
     File Name: 201412-1.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月24日 星期二 21时49分41秒
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
int num[1010];


int main(){
  int n,x;
  ios::sync_with_stdio(0);
  while(cin>>n){
    memset(num,0,sizeof num);
    for(int i=1;i<=n;++i){
      cin>>x;
      num[x]++;
      cout<<num[x];
      if(i==n)cout<<'\n';
      else cout<<' ';
    }
  }
}
