/*************************************************************************
     File Name: HDU1079.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月16日 星期六 20时29分37秒
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
int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int flag[110][20][40];

bool check(int y){
  return (y%4==0 && y%100) || y%400==0;
}

int main(){
  int y,m,d,i,j,k,t;
  int sy=2001,sm=11,sd=4;
  int ey=1900;
  int next=1;
  for(i=sy-ey;i>=0;--i){
    if(check(i+ey))month[2]=29;
    else month[2]=28;
    if(i!=sy-ey)sm=12;
    for(j=sm;j>=1;--j){
      if(i!=sy-ey || j!=11)sd=month[j];
      for(k=sd;k>=1;--k){
        if(next==2 || (j!=12 && flag[i][j+1][k]==2) || (j==12 && flag[i+1][1][k]==2))flag[i][j][k]=1;
        if(next!=2 && ((j!=12 && flag[i][j+1][k]!=2) || (j==12 && flag[i+1][1][k]!=2)))flag[i][j][k]=2;
        next=flag[i][j][k];
      }
    }
  }
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d%d",&y,&m,&d);
      if(flag[y-ey][m][d]==1)puts("YES");
      else puts("NO");
    }
  }
}
