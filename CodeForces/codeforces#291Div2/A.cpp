/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月14日 22:19:49
 ************************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cctype>
#include<climits>
using namespace std;

int main(){
  char x[1000];
  int i;
  scanf("%s",x);
  //cout<<x<<endl;
  int len=strlen(x);
  //cout<<"len="<<len<<endl;
  bool flag=0;
  for(i=0;i<len;++i){
    int xx=x[i]-'0';
    if(!i&&x[i]=='9')continue;
    //cout<<"xx="<<xx<<endl;
    if(xx>9-xx)x[i]=9-xx+'0';
    //cout<<x[i];
  }
  //cout<<endl;
 // for(i=0;i<len;++i){
 //   if(x[i]!='0'){
 //     flag=0;break;
 //   }
 // }
 // if(flag){
 //   puts("9");return 0;
 // }
  for(i=0;i<len;++i){
    if(x[i]-'0')flag=1;
    if(flag)printf("%c",x[i]);
  }
  puts("");
}
