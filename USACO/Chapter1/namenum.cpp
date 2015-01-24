/*************************************************************************
     File Name: namenum.cpp
     ID: obsoles1
     PROG: namenum
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月23日 19:25:58
 ************************************************************************/
#include<cstdio>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const char code[]="22233344455566670778889990";
string s,ss,dict;

int main(){
  freopen("namenum.in","r",stdin);
  freopen("namenum.out","w",stdout);
  ifstream tin("dict.txt");
  int flag=1,i;
  cin>>s;
  while(tin>>dict){
    //cout<<dict<<endl;
    ss.clear();
    if(s.length()!=dict.length())continue;
    if(code[dict[0]-'A']!=s[0])continue;
    for(i=0;dict[i];i++){
      //ss[i]=code[dict[i]-'A'];
      ss+=code[dict[i]-'A'];
      //printf("ss[%d]=%c\n",i,ss[i]);
      //cout<<ss<<endl;
    }
    if(s==ss.c_str())flag=0,cout<<dict<<'\n';
  }
  if(flag)puts("NONE");
}
