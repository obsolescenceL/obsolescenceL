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
    m['a']=0;
    m['b']=0;
    m['c']=0;
    m['d']=0;
    m['e']=0;
    m['f']=0;
    m['g']=0;
    m['h']=0;
    m['i']=0;
    m['j']=0;
    m['k']=0;
    m['l']=0;
    m['m']=0;
    m['n']=0;
    m['o']=0;
    m['p']=0;
    m['q']=0;
    m['r']=0;
    m['s']=0;
    m['t']=0;
    m['u']=0;
    m['v']=0;
    m['w']=0;
    m['x']=0;
    m['y']=0;
    m['z']=0;
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
