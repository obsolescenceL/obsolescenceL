/*************************************************************************
     File Name: c.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月16日 星期一 20时02分32秒
 ************************************************************************/
#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

bool cmp(char lhs,char rhs){
  if(tolower(lhs)!=tolower(rhs))
    return tolower(lhs)<tolower(rhs);
  return lhs<rhs;
}

int main(){
  int t;
  string s;
  while(~scanf("%d",&t)){
    while(t--){
      cin>>s;
      sort(s.begin(),s.end(),cmp);
      cout<<s<<endl;
      while(next_permutation(s.begin(),s.end(),cmp)){
        cout<<s<<endl;
      }
    }
  }
}
