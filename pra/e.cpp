/*************************************************************************
     File Name: e.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月31日 星期二 19时49分51秒
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
#include<vector>
#include<set>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
using namespace std;
set<int> s1,s2;

int main(){
  int n,i,x;
  while(cin>>n){
    s1.clear();
    s2.clear();
    for(i=0;i<n;++i){
      cin>>x;
      s1.insert(x);
    }
    for(i=0;i<n;++i){
      cin>>x;
      s2.insert(x);
    }
    if(s1==s2)cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
  }
}
