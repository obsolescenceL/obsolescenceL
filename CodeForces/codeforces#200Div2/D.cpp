/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月11日 星期一 09时15分54秒
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
char s[N];
stack<char> st;

int main(){
  int len,i;
  ios::sync_with_stdio(0);
  while(cin>>s){
    len=strlen(s);
    while(!st.empty())st.pop();
    st.push(s[0]);
    for(i=1;i<len;++i){
      if(st.empty() || st.top()!=s[i])
        st.push(s[i]);
      else st.pop();
    }
    if(st.empty())cout<<"Yes\n";
    else cout<<"No\n";
  }
}
