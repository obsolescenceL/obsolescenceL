/*************************************************************************
     File Name: f.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月13日 星期五 10时44分54秒
 ************************************************************************/
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string s;

int main(){
  while(cin>>s){
    if(s[0]=='#')break;
    if(next_permutation(s.begin(),s.end()))
      cout<<s<<endl;
    else cout<<"No Successor"<<endl;
  }
}
