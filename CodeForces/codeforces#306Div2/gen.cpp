#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  //freopen("in.txt","w",stdout);
  char ch1='A',ch2='B';
  for(int i=0;i<100000;++i)
    if(i%2)cout<<ch1;
    else cout<<ch2;
  //cout<<'\n';
  return 0;
}
