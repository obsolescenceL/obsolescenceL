/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  3/28 21:59:15 2016
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
const int N=2048+10,M=1024+10;
char mp[M][N];

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
    mp[x][y+1]='/',mp[x][y+2]='\\';
    mp[x+1][y]='/',mp[x+1][y+1]='_',mp[x+1][y+2]='_',mp[x+1][y+3]='\\';
    //cout<<"x="<<x<<endl;
    return;
  }
  Print(x,y+Pow(2,n-1),n-1);
  Print(x+Pow(2,n-1),y,n-1);
  Print(x+Pow(2,n-1),y+Pow(2,n),n-1);
}

int main(){
  int n,h,w,i,j;
  while(~scanf("%d",&n)&&n){
    //Mem0(mp);
    h=Pow(2,n),w=Pow(2,n+1);
    for(i=0;i<h;++i)
      for(j=0;j<w;++j)
        mp[i][j]=' ';
    //cout<<"h="<<h<<endl;
    //cout<<"w="<<w<<endl;
    Print(0,0,n);
    for(i=0;i<h;++i){
      for(j=0;j<w;++j)
        putchar(mp[i][j]);
      puts("");
    }
    puts("");
  }
}
