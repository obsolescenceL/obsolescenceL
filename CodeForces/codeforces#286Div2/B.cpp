/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月28日 14:06:55
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char s[100010];
int main(){
  char t;
  int i,x,len;
  while(cin>>s){
    len=strlen(s);
    x=-1;
    for(i=0;s[i];++i)
      if((s[i]-'0')%2==0){
        x=i;
        if(s[i]<s[len-1]) break;
      }
    if(x!=-1){
      t=s[len-1],s[len-1]=s[x],s[x]=t;
      cout<<s<<'\n';
    }else puts("-1");
  }
}

