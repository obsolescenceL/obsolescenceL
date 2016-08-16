/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月13日 星期一 20时52分42秒
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
using namespace std;
bool flag,ans[1000001];
int n,s[1000001],t[1000001];
stack<char> mys;

void dfs(int i,int j,int k){
  if(j==n){
    flag=1;
    return;
  }
  if(i<n){
    mys.push(s[i]),ans[k]=1;
    dfs(i+1,j,k+1);
    mys.pop();
  }
  if(!mys.empty()&&t[j]==mys.top()){
    int x=mys.top();
    mys.pop(),ans[k]=0;
    dfs(i,j+1,k+1);
    mys.push(x);
  }
}

int main(){
  ios::sync_with_stdio(0);
  while(cin>>n){
    flag=0;
    while(!mys.empty())mys.pop();
    for(int i=0;i<n;++i)cin>>s[i];
    for(int i=0;i<n;++i)cin>>t[i];
    dfs(0,0,0);
    if(flag)puts("Yes");
    else puts("No");
  }
}
