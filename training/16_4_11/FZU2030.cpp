/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  4/11 18:46:15 2016
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
const int N=20;
char s[N];
int len,cnt;

void dfs(int pos,int c){
  if(c<0)return;
  //cout<<"pos="<<pos<<" c="<<c<<endl;
  if(pos==len && !c){
    //cout<<"cnt="<<cnt<<endl;
    cnt++;return;
  }
  if(s[pos]=='(')dfs(pos+1,c+1);
  if(s[pos]==')')dfs(pos+1,c-1);
  if(s[pos]=='?'){
    dfs(pos+1,c+1);
    dfs(pos+1,c-1);
  }
}

int main(){
  while(~scanf("%s",s)){
    cnt=0;
    len=strlen(s);
    dfs(0,0);
    printf("%d\n",cnt);
  }
}
