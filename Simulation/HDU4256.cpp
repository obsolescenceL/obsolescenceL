/*************************************************************************
     File Name: k.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月12日 星期二 15时38分42秒
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
map<char,int> mp;

int main(){
  mp['I']=1;
  mp['V']=5;
  mp['X']=10;
  ios::sync_with_stdio(0);
  string s;
  int nc=0,i;
  while(cin>>s){
    int sum=mp[s[0]];
    bool flag=0;
    if(mp[s[0]]<mp[s[1]])sum=-sum;
    //cout<<"sum="<<sum<<endl;
    for(i=1;i<s.size()-1;++i){
      if(mp[s[i-1]]>=mp[s[i]])sum+=mp[s[i]];
      else sum-=mp[s[i]];
    }
    sum+=mp[s[i]];
    cout<<"Case "<<++nc<<": "<<sum<<'\n';
  }
}
