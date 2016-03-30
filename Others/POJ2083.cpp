/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 二  3/29 19:42:17 2016
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
const int N=2187+10;
char mp[N][N];

int Pow(int x,int k){
  int ans=1;
  for(;k;k>>=1){
    if(k&1)ans*=x;
    x*=x;
  }
  return ans;
}

void Print(int x,int y,int n){
  if(n==1){
    mp[x][y]=mp[x][y+2]=mp[x+1][y+1]=mp[x+2][y]=mp[x+2][y+2]='X';
    return;
  }
  Print(x,y,n-1);
  Print(x,y+2*Pow(3,n-1),n-1);
  Print(x+Pow(3,n-1),y+Pow(3,n-1),n-1);
  Print(x+2*Pow(3,n-1),y,n-1);
  Print(x+2*Pow(3,n-1),y+2*Pow(3,n-1),n-1);
}

int main(){
  int n,i,j,a;
  while(~scanf("%d",&n)&&n!=-1){
    if(n==1){puts("X\n-");continue;}
    a=Pow(3,n-1);
    for(i=0;i<a;++i)
      for(j=0;j<a;++j)
        mp[i][j]=' ';
    Print(0,0,n-1);
    for(i=0;i<a;++i){
      for(j=0;j<a;++j)
        putchar(mp[i][j]);
      puts("");
    }
    puts("-");
  }
}
