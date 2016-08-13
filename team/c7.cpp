/*************************************************************************
     File Name: c7.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月22日 星期日 19时34分02秒
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
using namespace std;

int main(){
  int n,i,a;
  while(~scanf("%d",&n)){
    stack<int> s;
    int maxn=-1;
    for(i=0;i<n;++i){
      scanf("%d",&a);
      while(!s.empty()){
        int x=s.top();
        maxn=max(maxn,x^a);
        if(a<=x)break;
        s.pop();
      }
      s.push(a);
    }
    printf("%d\n",maxn);
  }
}
