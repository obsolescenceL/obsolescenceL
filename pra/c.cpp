/*************************************************************************
     File Name: c.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月31日 星期二 18时00分00秒
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
set<pair<char,char> > mys;
pair<char,char> p;
string s;


int main(){
  while(cin>>s && s!="*"){
    bool flag=1;
    for(int i=1;s[i]&&flag;++i){
      mys.clear();
      for(int j=0;s[i+j]&&flag;++j){
        p=make_pair(s[j],s[j+i]);
        if(mys.count(p)){
          flag=0;
          cout<<s<<" is NOT surprising."<<'\n';
        }
        mys.insert(p);
      }
    }
    if(flag) cout<<s<<" is surprising."<<'\n';
  }
}
