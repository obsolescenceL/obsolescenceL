/*************************************************************************
     File Name: FileFix-it.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月27日 星期五 21时08分23秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>
using namespace std;
typedef set<string> SS;
typedef vector<string> SV;
#define pb(a) push_back(a)
SS myset;
int cnt;

SV split(string s1){
  SV v;
  string s="/";
  for(int i=1;s1[i];++i){
    if(s1[i]=='/'){
      v.pb(s);
    }
    s+=s1[i];
  }
  v.pb(s);
  return v;
}

void add(SV v){
  for(int i=0;i<v.size();++i)
    myset.insert(v[i]);
}

void solve(SV v){
  for(int i=0;i<v.size();++i){
    if(!myset.count(v[i]))cnt++;
    myset.insert(v[i]);
  }
}

int main(){
  string s1;
  int t,n,m,i,j;
  ios::sync_with_stdio(0);
  while(cin>>t){
    for(int ncase=1;ncase<=t;++ncase){
      cin>>n>>m;
      myset.clear();
      while(n--){
        cin>>s1;
        SV v=split(s1);
        add(v);
      }
      cnt=0;
      while(m--){
        cin>>s1;
        SV v=split(s1);
        solve(v);
      }
      printf("Case #%d: %d\n",ncase,cnt);
    }
  }
}
