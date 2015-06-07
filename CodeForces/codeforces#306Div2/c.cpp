/*************************************************************************
     File Name: c.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月05日 星期五 09时39分59秒
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
  ios::sync_with_stdio(0);
  int n,i,j,k;
  bool flag=1;
  string s;
  cin>>s;
  for(i=0;s[i]&&flag;++i)
    if((s[i]-'0')%8==0){
      flag=0;
      cout<<"YES\n";
      cout<<s[i]<<'\n';
      break;
    }
  for(i=0;s[i]&&flag;++i)
    for(j=i+1;s[j]&&flag;++j)
      if(((s[i]-'0')*10+s[j]-'0')%8==0){
        flag=0;
        cout<<"YES\n";
        cout<<s[i]<<s[j]<<'\n';
        break;
      }
  for(i=0;s[i]&&flag;++i)
    for(j=i+1;s[j]&&flag;++j)
      for(k=j+1;s[k]&&flag;++k)
        if(((s[i]-'0')*100+(s[j]-'0')*10+s[k]-'0')%8==0){
          flag=0;
          cout<<"YES\n";
          cout<<s[i]<<s[j]<<s[k]<<'\n';
          break;
        }
  if(flag)cout<<"NO\n";
}
