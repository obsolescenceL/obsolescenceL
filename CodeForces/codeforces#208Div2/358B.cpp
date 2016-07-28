/*************************************************************************
     File Name: B.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月23日 星期六 09时41分44秒
 ************************************************************************/
#include<bits/stdc++.h>
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
const int N=1e5+10;
string s[N],ss;

int main(){
  int n,i,j;
  while(cin>>n){
    for(i=0;i<n;++i)
      cin>>s[i];
    cin>>ss;
    int pos=0;
    bool flag=1;
    while(ss[pos] && ss[pos]!='<')pos++;
    if(!ss[pos])flag=0;
    else pos++;//!!!
    while(ss[pos] && ss[pos]!='3')pos++;
    if(!ss[pos])flag=0;
    else pos++;
    for(i=0;i<n && flag;++i){
      for(j=0;s[i][j] && flag;++j){
        while(ss[pos] && ss[pos]!=s[i][j])pos++;
        if(!ss[pos])flag=0;
        else pos++;
      }
      while(ss[pos] && ss[pos]!='<')pos++;
      if(!ss[pos])flag=0;
      else pos++;
      while(ss[pos] && ss[pos]!='3')pos++;
      if(!ss[pos])flag=0;
      else pos++;
    }
    if(flag)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
}
