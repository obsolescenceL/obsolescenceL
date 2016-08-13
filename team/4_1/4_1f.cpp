/*************************************************************************
     File Name: 4_1f.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月01日 星期三 18时39分32秒
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
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
using namespace std;
const int N=31;
char x[N],s[N];

int main(){
  int n,i,j,nc=0;
  ios::sync_with_stdio(0);
  while(cin>>n){
    memset(s,0,sizeof s);
    for(i=0;i<n*2-1;++i){
      cin>>x;
      for(j=0;j<strlen(x);++j)
        s[j]^=x[j];
    }
    cout<<"Scenario #"<<++nc<<'\n';
    cout<<s<<"\n\n";
  }
}
