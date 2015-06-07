/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月05日 星期五 00时43分53秒
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
#include<vector>
#include<set>
#include<bitset>
using namespace std;
char s[100001];

int main(){
  ios::sync_with_stdio(0);
  cin>>s;
  bool flag=0;
  int n=strlen(s),pos_ab,pos_ba,p,q;
  p=-1,q=-1;
  for(p=0;p<=n-2;++p)
    if(s[p]=='B'&&s[p+1]=='A')
      break;
  for(q=n-2;q>=0;--q)
    if(s[q]=='A'&&s[q+1]=='B')
      break;
  if(p>=0&&q>=0&&q>p+1)flag=1;

  p=-1,q=-1;
  for(p=0;p<=n-2;++p)
    if(s[p]=='A'&&s[p+1]=='B')
      break;
  for(q=n-2;q>=0;--q)
    if(s[q]=='B'&&s[q+1]=='A')
      break;
  if(p>=0&&q>=0&&q>p+1)flag=1;
  if(flag) cout<<"YES"<<'\n';
  else cout<<"NO"<<'\n';
}
