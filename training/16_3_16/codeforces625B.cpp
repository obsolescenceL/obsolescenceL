/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 三  3/16 19:18:35 2016
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
const int N=100010;
char s1[N],s2[50];
int len1,len2;

bool check(int x){
  for(int i=0;i<len2;++i)
    if(s1[x+i]!=s2[i])return 0;
  return 1;
}

int main(){
  int ans;
  ios::sync_with_stdio(0);
  while(cin>>s1>>s2){
    ans=0;
    len1=strlen(s1),len2=strlen(s2);
    for(int i=0;i<len1;++i){
      if(s1[i]==s2[0])
        if(check(i))ans++,i+=len2-1;
    }
    cout<<ans<<endl;
  }
}
