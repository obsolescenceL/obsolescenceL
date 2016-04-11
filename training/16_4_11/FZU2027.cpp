/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  4/11 17:07:35 2016
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
#include<bitset>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
//const int N=110;
string s,tmp;
set<string> mys;

int main(){
  int i,j;
  while(cin>>s){
    mys.clear();
    int len=s.size();
    for(i=j=0;i<len;tmp.clear(),++i){
      while(isalpha(s[i])){
        tmp+=s[i++];
      }
      //tmp+='\0';
      if(!mys.count(tmp) && tmp!="")
        cout<<tmp<<endl;
      mys.insert(tmp);
    }
  }
}
