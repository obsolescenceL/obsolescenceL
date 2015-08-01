/*************************************************************************
     File Name: I.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月29日 星期三 13时44分59秒
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
#include<sstream>
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
struct node{
  int cnt,v;
  bool operator < (const node & rhs) const {
    return cnt>rhs.cnt || (cnt==rhs.cnt && v>rhs.v);
  }
}c[30];
string s,ss;

int main(){
  int t,i;
  ios::sync_with_stdio(0);
  while(cin>>t){
    for(int nc=1;nc<=t;++nc){
      Mem0(c);
      while(getline(cin,s)&&s[0]!='*'){
        istringstream stream(s);
        while(stream>>ss){
          for(i=0;i<ss.size();++i){
            ss[i]=tolower(ss[i]);
            c[ss[i]-'a'].cnt++;
          }
        }
      }
      for(i=0;i<26;++i)
        c[i].v=i;
      sort(c,c+26);
      int temp=0;
      for(i=0;i<5;++i)
        if(c[i].cnt)temp+=c[i].v;
      printf("Case %d: ",nc);
      if(temp>62)puts("Effective");
      else puts("Ineffective");
    }
  }
}
