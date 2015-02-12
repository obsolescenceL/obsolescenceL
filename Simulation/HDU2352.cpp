/*************************************************************************
     File Name: F.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月12日 13:58:56
 ************************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<iostream>
#include<cctype>
using namespace std;
map<char,int> s;
char ss[100];

int main(){
  s['I']=1;
  s['V']=5;
  s['X']=10;
  s['L']=50;
  s['C']=100;
  s['D']=500;
  s['M']=1000;
  int n;
  while(~scanf("%d",&n)){
    while(n--){
      scanf("%s",ss);
      int sum=s[ss[0]];
      for(int i=1;ss[i];++i){
        if(s[ss[i]]>s[ss[i-1]])sum-=2*s[ss[i-1]];
        sum+=s[ss[i]];
      }
      printf("%d\n",sum);
    }
  }
}
