/*************************************************************************
     File Name: b.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月31日 星期二 17时26分58秒
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
#include<sstream>
#include<set>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
using namespace std;
string x,str;
set<string> s;


int main(){
  while(getline(cin,x) && x!="#"){
    s.clear();
    istringstream stream(x);
    while(stream>>str)
      s.insert(str);
    cout<<s.size()<<endl;
  }
}

