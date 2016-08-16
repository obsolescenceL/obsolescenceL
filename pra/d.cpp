/*************************************************************************
     File Name: d.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月31日 星期二 19时24分19秒
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
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
using namespace std;
set<int> s;

int main(){
  int n,m,x;
  while(cin>>n>>m){
    s.clear();
    for(int i=0;i<n+m;++i){
      cin>>x;
      s.insert(x);
    }
    bool first=0;
    each(it,s){
      if(first) cout<<' ';
      cout<<*it;
      first=1;
    }
    cout<<'\n';
  }
}
