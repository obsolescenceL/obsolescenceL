/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月27日 星期五 00时30分02秒
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
char s[200000];
map<char,int> m;

int main(){
  int n;
  while(~scanf("%d",&n)){
    scanf("%s",s);
    for(int i=0;i<26;++i)
      m['a'+i]=0;
    int cnt=0;
    for(int i=0;i<2*n-2;++i){
      if(i%2){
        if(m[s[i]-'A'+'a']>0)
          m[s[i]-'A'+'a']--;
        else cnt++;
      }else{
        m[s[i]]++;
      }
    }
    printf("%d\n",cnt);
  }
}
