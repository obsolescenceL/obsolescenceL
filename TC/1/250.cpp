/*************************************************************************
     File Name: 250.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月26日 星期四 09时24分27秒
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

class SquareScoresDiv2{
  public:
    int getscore(string);
};

//int SquareScoresDiv2::getscore(string s){
int main(){
  string s;
  cin>>s;
  int len=s.size();
  int ans=len;
  for(int i=2;i<=len;++i){
    for(int j=0;j+i<=len;++j){
      bool flag=1;
      for(int k=i-1;k;k--){
        if(s[j]!=s[j+k])flag=0;
      }
      if(flag)ans++;
    }
  }
  //return ans;
  cout<<ans<<endl;
}
