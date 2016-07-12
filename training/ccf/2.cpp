/*************************************************************************
     File Name: 2.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 三  3/23 20:15:45 2016
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
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;

int main(){
  int i,j,ans=0;
  char s[100];
  scanf("%s",s);
  for(i=j=0;i<11;++i){
    if(s[i]=='-')continue;
    j++;
    ans+=j*(s[i]-'0');
  }
  ans%=11;
  if(ans==s[12]-'0' || (ans==10 && s[12]=='X'))puts("Right");
  else{
    if(ans==10)s[12]='X';
    else s[12]=ans+'0';
    printf("%s\n",s);
  }
  return 0;
}
